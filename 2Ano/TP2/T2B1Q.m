function [CLt]=T2B1Q(bitt, a, Ts)
% Gera um codigo 2B1Q funcao dos bits de entrada
% [CLt]=T2B1Q(bitt, a, Ts)
% Inputs: bits - bitt a codificar
%                a - Distância entre simbolos
%                Ts - Numero de pontos (par) por simbolo
% Output: CLt - Codigo 2B1Q
%
% Exemplo bitt=[0 0 0 1 1 1 1 0]; a=2; Ts=2;
%         CLt=[-3 -3 -1 -1 1 1 3 3]

CLt=[];
for i=1:2:length(bitt)
    A=3*a/2;
    if bitt(i+1)
        A=a/2;
    end
    if ~bitt(i)
        A=-A;
    end
    CLt=[CLt A*ones(1, Ts)];
end
    