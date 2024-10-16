%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Inform�tica, Redes e Telecomunica��es
%
% SS  - Sinais e Sistemas
%
%
% frequencyToTime.m
% Calcula os valores das amostras do sinal no tempo a partir dos coeficientes CK com base na fun��o ifft() do MATLAB
% Recebe:
%       CK, coeficientes CK.
%       Fs, frequ�ncia de amostragem do sinal x.
% Retorna:
%       t, eixo dos tempos
%       signal, amostras do sinal obtidas a partir dos coeficientes CK .

function [t, signal] = frequencyToTime( CK, Fs )


% Calcula o eixo do tempo
t = (0 : 1 : length(CK)-1) / Fs;
%freq = ((0 : 1 : length(x)-1)*Fs / ( length(x) )) - Fs/2;

% Sinal no dom�nio do .
% Calcula a Inversa da Transformada R�pida de Fourier (IFFT) dos coeficientes CK e desloca a componente de frequ�ncia zero para o centro. Por fim multiplica pela quantidade dos coeficientes CK para escalar corretamente.
signal = (ifft(ifftshift(CK)))*length(CK);

return;

