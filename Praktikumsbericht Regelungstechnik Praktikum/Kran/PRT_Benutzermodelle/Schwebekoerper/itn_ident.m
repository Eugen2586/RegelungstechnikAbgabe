function [S,Tu,K,n,T,F]=itn_ident(t,y)
% Identifikation eines ITn-Gliedes aus der Tangente und der Krümmung 
% der Sprungantwort

% Kanditaten für Zeit, ab der die Tangente angelegt wird
te = t(end);
tc = linspace(0,te/2,21);
tc = tc(2:21); % 20 Stück bis zur halben Endzeit

% prozentualer Fehler für Auswahl der Tangente
ftp=1; 

% prozentualer Fehler für Auswahl der Sprungantwort
fsp=50; % größerer Fehler führt zu kleinerem n

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% verschiedene Tangenten Testen und dazugehörigen Fehler berechnen 

nt   = length(t);
nc   = length(tc);
Sv   = zeros(nc,1);
Tuv  = zeros(nc,1);
fehl = zeros(nc,1);

for ic=1:nc

  % ab wo die Tangente?
  ig = find(t>tc(ic));

  % Auswahl
  tg = t(ig);
  yg = y(ig);
  ng =length(tg);

  % Tangente = a*t+b ; ab = [a b]
  ab = [tg ones(ng,1)]\yg;

  % Steigung und Schnittpunkt 
  Sv(ic)  = ab(1);
  Tuv(ic) = -ab(2)/ab(1);
  
  % Fehler ab 2*Schnittpunkt
  ifehl = find(t>2*Tuv(ic));
  dyfehl = y(ifehl) - (ab(1)*t(ifehl)+ab(2));
  fehl(ic) = norm(dyfehl)/sqrt(length(ifehl));
  
end

% beste Tangente finden (kleinsten Fehler bis auf 1%)

iklein = find(fehl<min(fehl)*(1+ftp/100));
iwahl = min(iklein);

S = Sv(iwahl);
Tu = Tuv(iwahl);

if nargout <= 2
  return
end

% verschiedene n testen und bestes auswählen

K   = S; 
% I-Anteil
FI  = tf(K,[1 0]);
Fav = cell(3,1);
fyv = zeros(3,1);

for n = 1:6

  % PT1-Anteil
  T    = Tu/n;
  FPT1 = tf(1,[T 1]);
  
  % Kandidat für ITn
  Fa = FI;
  for in = 1:n
    Fa = Fa*FPT1;
  end
  Fav{n}=Fa;

  % Sprungantwort und Fehler des Kandidaten
  ya = step(Fa,t);
  fy(n) = norm(y-ya)/sqrt(nt);

end


% besten Kandidaten auswählen ( minimales n mit max 10% Fehler)
nklein = find(fy<min(fy)*(1+fsp/100));
n = min(nklein);
T = Tu/n;
F = Fav{n};
