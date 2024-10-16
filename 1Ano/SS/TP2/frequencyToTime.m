%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Informática, Redes e Telecomunicações
%
% SS  - Sinais e Sistemas
%
%
% frequencyToTime.m
% Calcula os valores das amostras do sinal no tempo a partir dos coeficientes CK com base na função ifft() do MATLAB
% Recebe:
%       CK, coeficientes CK.
%       Fs, frequência de amostragem do sinal x.
% Retorna:
%       t, eixo dos tempos
%       signal, amostras do sinal obtidas a partir dos coeficientes CK .

function [t, signal] = frequencyToTime( CK, Fs )


% Calcula o eixo do tempo
t = (0 : 1 : length(CK)-1) / Fs;
%freq = ((0 : 1 : length(x)-1)*Fs / ( length(x) )) - Fs/2;

% Sinal no domínio do .
% Calcula a Inversa da Transformada Rápida de Fourier (IFFT) dos coeficientes CK e desloca a componente de frequência zero para o centro. Por fim multiplica pela quantidade dos coeficientes CK para escalar corretamente.
signal = (ifft(ifftshift(CK)))*length(CK);

return;

