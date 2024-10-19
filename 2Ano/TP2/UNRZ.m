function CLt=UNRZ(bits, A, Tb)
% Gera um codigo de linha UNRZ funcao dos bits de entrada
% CLt=UNRZ(bits, A, Tb)
% Input: bits - bits de entrada
%        A - Amplitude do codigo
%        Tb - Numero de pontos (par) por simbolo
% Output CLt - Codigo UNRZ

s1=A*[ones(1, Tb)];
s0=zeros(1, Tb);

CLt=[];
for i=1:length(bits)
    if bits(i)
        CLt=[CLt s1];
    else
        CLt=[CLt s0];
    end
end
end
