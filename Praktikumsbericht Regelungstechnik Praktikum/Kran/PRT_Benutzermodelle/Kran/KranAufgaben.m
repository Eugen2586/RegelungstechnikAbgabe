clear
clc
%% Modelleinstellungen
% je nach Aufgabe ist das jeweilige Modell auszuwaehlen! Syntax: KranAufgX,
% X={3,...,7}
modelslx='KranAufg4';
load_system(modelslx);
h=get_param(modelslx, 'modelworkspace');
simTime=10;
T_S=0.01;
Ts=T_S;

%% Aufgabe 3: Regelung Wagenposition
%auch die anderen Aufgaben ^^
clc
%Tools:
%sisotool;
T=0.45;
Ks=1;
Tdy=0.3;
Kpy=3.8;
Tda=0.09;
Kpa=-10.3;


Ry=5;
Ra=-2.6001;
%Konstanten (gegeben):
kvy=50;
kfy=17.6;
mw=1.03;
mc=0.481;
R=0.5;
g=9.81;
%Übertragungsfunktionen
s=tf('s');
%Gstrecke=tf(linsys1);
%pole(linsys1);
t=3/0.09;

% Resultat:
%alt:
% Gstrecke =
%  
%   From input "Winkelregelung44bb/In1" to output "Aist":
%         -34.17 s^2 - 3318 s + 1.059e-12
%   -------------------------------------------
%   s^4 + 48.54 s^3 + 114.2 s^2 + 1842 s + 1676
%  
% Name: Linearization at model initial condition
% Continuous-time transfer function.
% 
% 
% ans =
% 
%  -46.9300 + 0.0000i
%   -0.3350 + 6.1432i
%   -0.3350 - 6.1432i
%   -0.9437 + 0.0000i

% neu:
% Gstrecke =
%  
%   From input "untitled/In1" to output "Aist":
%          -34.18 s + 0.04443
%   ---------------------------------
%   s^3 + 48.54 s^2 + 28.78 s + 952.4
%  
% Name: Linearization at model initial condition
% Continuous-time transfer function.
% 
% 
% ans =
% 
%  -48.3558 + 0.0000i
%   -0.0939 + 4.4370i
%   -0.0939 - 4.4370i



%ywsoll=1;



%% Aufgabe 4: Zusaetzliche Regelung des Winkels alpha
% Ralpha=;

%% Aufgabe 5: Digitale PD-Regelung von yw und alpha
% KPy=;
% TDy=;
% KPalpha=;
% TDalpha=;

% K=;
% T=;

%% Aufgabe 7: Regelung der x- und y-Achse
% xwsoll=0.5;

%% Build Model / connect / start
set_param(modelslx,'StartTime','0','StopTime',int2str(simTime));

slbuild(modelslx);
set_param(modelslx,'SimulationCommand','connect');
set_param(modelslx,'SimulationCommand','start');

%% Aktivitaet des Krans feststellen
while true
    plantStatus=get_param(modelslx,'Simulationstatus');
    if strcmp(plantStatus, 'external')
        clc
        disp('...Experiment aktiv...')
        pause(0.1)
    elseif strcmp(plantStatus, 'stopped') || strcmp(plantStatus, 'terminating')
        clc
        disp('...Experiment abgeschlossen...')
        break
    elseif strcmp(plantStatus, 'terminating')
        clc
        disp('...Experiment abgebrochen...')
        break
    end
end

%% Daten anzeigen
figure(1), clf
subplot(3,1,1), plot(Position.time, Position.signals.values(:,2)), xlabel('Zeit [t]'), ylabel('Position Y [m]'), grid on
subplot(3,1,2), plot(Winkel.time, Winkel.signals.values(:,2)), xlabel('Zeit [t]'), ylabel('Winkel \alpha [rad]'), grid on
subplot(3,1,3), plot(Stellsignal.time, Stellsignal.signals.values(:,2),'color', [0 0.4470 0.7410]), hold on, 
                plot([Stellsignal.time(1), Stellsignal.time(end)], [1 1],[Stellsignal.time(1), Stellsignal.time(end)], -[1 1],'color', [0.8500 0.3250 0.0980]), xlabel('Zeit [t]'), ylabel('uy'), grid on

if strcmp(modelslx,'KranAufg7')
    figure(2), clf
    subplot(3,1,1), plot(Position.time, Position.signals.values(:,1)), xlabel('Zeit [t]'), ylabel('Position X [m]'), grid on
    subplot(3,1,2), plot(Winkel.time, Winkel.signals.values(:,1),'color', [0 0.4470 0.7410]), xlabel('Zeit [t]'), ylabel('Winkel \beta [rad]'), grid on
    subplot(3,1,3), plot(Stellsignal.time, Stellsignal.signals.values(:,1),'color', [0 0.4470 0.7410]), hold on,
                    plot([Stellsignal.time(1), Stellsignal.time(end)], [1 1],[Stellsignal.time(1), Stellsignal.time(end)], -[1 1],'color', [0.8500 0.3250 0.0980]), xlabel('Zeit [t]'), ylabel('ux'), grid on
end
