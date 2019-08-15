clc
%Thema: Roboterarm Teil2 Aufgabe 9.3
%Linearisierung eines nichtlinearen Systems um einen Stabilen
%       Zustand herum.

%Verfahren:
%1.)    Blockschaltbild eines (nicht linearen) Systems erstellen
%2.)    Ruhelage(n) des Systems bestimmen und geeignet w�hlen
%3.)    Modell linearisieren mit Hilfe von Trim Model

% ---hier Ende des Linearisierungsprozesses---

%4.)    Regler f�r lineares Modell entwerfen
%5.)    Regler f�r nichtlineares Modell �bernehmen

%Deklaration:

%Vorgegeben:
s=tf('s');
m=7;
l=1;
g=9.81;
c=1;
K=300;
T=0.1;

%Eingef�hrte:


%Funktionen:

%G_Motors=tf(linsys1);
%G_Robos=tf(linsys2);


%Reglertypen:;
Kp=1;

Kr=1;

Ti=1;
Tv=1;

G_Ps=Kr;

G_PIs=Kr*(1+1/Ti*s);
%G_PI=Kr*(Ti*s+1)/(Ti*s);

%G_PDs=Kp*(1+Tv*s);
G_PDs=Kp*(s/s+1);

G_PIDs=Kp*(1+1/(Ti*s)+Tv*s);






%Tools:

%ltiview;
%simulink;
sisotool;


%Resultat:

% zu 3a Konstruktion:

% �bertragungsfunktion des Motors:
% 
% G_Motors =
%  
%   From input "In u" to output "Integrator":
%    3000
%   ------
%   s + 10
%  
% Name: Linearization at model initial condition
% Continuous-time transfer function.

% �bertragungsfunktion des Roboterarms:
% G_Robos =
%  
%   From input "In1" to output "Integrator":
%          0.1429
%   ---------------------
%   s^2 + 0.1429 s + 9.81
%  
% Name: Linearization at model initial condition
% Continuous-time transfer function.

%zu 3b:
%Screenshot wurde angelegt.
%Arm wurde zu beginn ausgelenkt und f�ngt an, hin und her zu pendelt
%Ged�mpfte Schingung (Modell zu entnehmen)
%Wie �blich Winkel, Winkelgeschw. und Winkelbeschl. jeweils um 90�
%Phasenverschoben


%zu 3c:
%Das System befindet sich zun�chst in Ruhelage
%zum Zeitpunkt t=1 wird ein Drehmoment eingepr�gt,
%das den Roboterarm nach Durchlaufen eines Einschwingvorgangs 
%um die neue Ruhelage in eben diese auslenkt.



%zu 3d:
%Anders als im Versuch 9.3c befindet sich der Roboterarm nun zum Zeitpunkt
%t=0 nicht mehr in der Ruhelage bei einem Winkel von 0�, sondern in einem 
%Winkel von 40�.Dies hat zur Folge, dass der Arm zun�chst 
%in der Zeit bis t=1s
%sowie in der darauffolgenden S�ttigungszeit des pt1_Gliedes,
%das den Motor beschreibt, zur�ckschwingen kann.
%Sobald das Drehmoment des Motors aufgebaut ist legt der Roboterarm 
%an Geschwindigkeit zu und �berschreitet dabei sogar die kritische 180�
%Marke, ab der der Arm nicht mehr zur�ckschwingt, sondern einen �berschlag
%vollf�hrt und weiter an Geschwindigkeit gewinnt.
%Da es sich bei dem betrachtetet Roboterarm um ein ged�mpftes Model
%handelt, geht die Gewschwindigkeit in eine S�ttigung �ber, bis diese um
%einen konstanten Wert fluktuiert.


%zu 3e:
%Aussage kann innerhalb eines gewissen Rahmens
%(Siehe Diagramme) best�tigt werden 



%zu 3f:

%Code:

%G_fs=tf(linsys1);
%test=2.456e4;
G_ffail=24560/(s^3 + 10.14*s^2 + 8.944*s + 75.15);
%�bertragungsfkt. des Systems (egal ob linear oder nicht):
%U0 hat keinen Impact auf die SprungImpulsantwort
G_ffests=426.6/(s^3+10.14*s^2*8.944*s*75.15);
G_fmusters=428.57/((s+10)*(s^2+0.1429*s+7.515));

%Notizen:
% 
% G_fs =
%  
%   From input "Linearisierung3_RoboKomplettmodell_Sim/In1" to output "Roboterarm":
%               2.456e04
%   ---------------------------------
%   s^3 + 10.14 s^2 + 8.944 s + 75.15
%  
% Name: Linearization around the operating point "op_trim2"
% Continuous-time transfer function.
%
%   Fehlerbehebung, Radiant als Augang w�hlen
%   Offset einf�hren nur bedingt hilfreich, da S�ttigung vorhanden.


%�bertragungsfunktion nach Korrektur:
%(Ergebnis stimmt nun mit der Musterl�sung �berein.)
%   G_fs =
%  
%   From input "Linearisierung3_RoboKomplettmodell_Sim/In1" to output "Roboterarm/Integrator":
%                 428.6
%   ---------------------------------
%   s^3 + 10.14 s^2 + 8.944 s + 75.15
%  
% Name: Linearization at model initial condition
% Continuous-time transfer function.

%Ende







