function bitr=R2B1Q(CLr, a, Ts)
% Recetor otimo 2B1Q 
% bitr=R2B1Q(CLr, a, Ts)
% 
% Input:  CLr - Codigo binário (com ruído)
%         a - Distância entre simbolos
%         Ts - Numero de pontos (par) por simbolo
% Output: bitsr - bits descodificados


% Exemplo CLt=[-3 -3 -1 -1 1 1 3 3]; a=2; Ts=2;
%         bitt=[0 0 0 1 1 1 1 0]

vd=[-a*Ts 0 a*Ts];
bitr=[];

for i=1:Ts:length(CLr)
    y =sum(CLr(i:i+Ts-1));
    ind=quantiz(y, vd);
    j=bin2gray(ind, 'pam', 4);
    bitr=[bitr de2bi(j, 2, 'left-msb')];
end
        
    
