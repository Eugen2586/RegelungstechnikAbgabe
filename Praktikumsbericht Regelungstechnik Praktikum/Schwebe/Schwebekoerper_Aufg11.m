clc
s=tf('s');

%Variablen:
Tstrich=0.4;
n=3;

Gbruch=(1+C*G)/(C*G);
Gvor=1/((1+Tstrich*s)^(n+1))*Gbruch

Gvorkurz=minreal(Gvor)