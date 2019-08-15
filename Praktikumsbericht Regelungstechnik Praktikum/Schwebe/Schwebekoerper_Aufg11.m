clc
s=tf('s');
%Variablen:
Tstrich=0.4;
n=3;
%Tstrich = sym('Tstrich'); 

Gbruch=(1+cV*gV)/(cV*gV);

Gvor=1/((1+Tstrich*s)^(n+1))*Gbruch


%Gvorkurz=minreal(Gvor)