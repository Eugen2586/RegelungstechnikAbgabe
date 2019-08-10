% Grafische Identifikation der gemessenen Sprungantwort des
% Schwebekörper-Versuchs
% Ausgegangen wird von einer positiven Sprungantwortmessung vom Nullpunkt
% des Aufbaus.
figure
clc
set(gcf,'position',[472 158 560 758]);
% aktuelles Datum und Uhrzeit werden erzeugt
    Datum = datestr(now);  
% Daten aus dem Workspace einlesen
y = y_t_Dat.signals.values;
t = y_t_Dat.time;
Step = u_t_Dat.signals.values;
step_max = max(Step);
% Sprungzeitwert und Sprunghöhe ermitteln
st = find(Step==step_max);
tStep_ind = st(1);           % Sprungzeitindex
u_delta = Step(tStep_ind)-Step(tStep_ind-1);         % Sprunghöhe
tStep = t(tStep_ind);
yStep = y(tStep_ind);
% Skalierung der Sprungantwort ändern (Zeitachse verschieben, so dass der 
% Sprungzeitpunkt t = 0 entspricht).
ymax_itn = max(y)-max(y)/10;
tind = find(t>=tStep&y<=ymax_itn);
t = t(tind)-tStep;
y = y(tind)-yStep;
% Sprungantwort darstellen
subplot(2,1,1)
plot(t,y);
% Achsenbeschriftung
    xlabel('t in sec');
    ylabel('h(t)','rotation',0);
    title(['Sprungantwort-Identifikation, am ',num2str(Datum)]);
% Funktionsendwert ermitteln
yend = y(end);
tend = t(end); 
% Identifizierungsfunktion aufrufen
[S,Tu,K,n,T,F]=itn_ident(t,y);
% Funktionswerte ermitteln
Tu_ind = find(t<=Tu);
Tu_ind = Tu_ind(end);
yTu = y(Tu_ind);

Gv = tf(1,[T 1]);
Gv = Gv^n;
G = K*tf(1,[1 0])*Gv

% Zeichnen der Tangente und der für die grafische Identifikation nötigen Hilsgeraden
line([0 tend],[0 0],'color','c','LineWidth',1);
line([Tu tend],[0 yend],'color','k','LineWidth',1);
line([Tu Tu],[0 yTu],'color','k','LineWidth',1);
line([0 Tu],[yTu yTu],'color','k','LineWidth',1);
line([tend tend],[0 yend],'color','k','LineWidth',1,'LineStyle','--');
line([0 tend],[yend yend],'color','k','LineWidth',1,'LineStyle','--');

hold on

% Überprüfen der identifizierten Sprungantwort durch den
% Vergleich mit der gemessenen Sprungantwort
yitn = step(F,t);
plot(t,yitn,'r-')

% Informationsfenster erzeugen  
    subplot(2,1,2)
    axis off;
    set(gcf,'color',[1 1 1]);
 
    
    
    str1(1) = {['Wichtige Parameter der Sprungantwort']};
    str1(2) = {['']};
    str1(3) = {['identifizierte Streckenverstärkung S = ',num2str(S,3)]};
    str1(4) = {['identifizierte Verzugszeitkonstante Tu = ',num2str(Tu,2),' sec']};
    str1(5) = {['Anzahl der Verzögerungsglieder n = ',num2str(n)]};
    str1(6) = {['Verzögerungszeitkonstante T = ',num2str(T,2),' sec']};
    str1(7) = {['']};
    str1(8) = {['ermittelte Sprunghöhe = ',num2str(u_delta)]};   
    str1(9) = {['h(tend) = ',num2str(yend)]};
    str1(10) = {['tend = ',num2str(tend),' sec']};
    str1(11) = {['h(Tu) = ',num2str(yTu,2)]};
    
    
 
    text(0,0.7,str1);
    
% Nicht benötigte Variablen löschen
clear step_max st tStep_ind u_delta tStep yStep ymax_itn tind yend tend F Gv yitn yTu Tu_ind
    
    
    
    
    
    
    