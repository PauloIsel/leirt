%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Inform�tica, Redes e Telecomunica��es
%
% SS  - Sinais e Sistemas
%
%
% timeTofreqqunecy.m
% Calcula os coeficientes CK do sinal x com base na fun��o fft() do MATLAB
% Recebe:
%       x, sinal no dom�nio do tempo.
%       Fs, frequ�ncia de amostragem do sinal x.
% Retorna:
%       freq, eixo da frequ�ncia
%       CK, valores dos coeficientes CK.

function [freq, CK] = timeTofrequency( x, Fs )


% Calcula o eixo da frequ�ncia
freq = ((0 : 1 : length(x)-1)*Fs / ( length(x) )) - Fs/2;

% Espectro.
% Calcula a Transformada R�pida de Fourier (FFT) do sinal x e desloca a componente de frequ�ncia zero para o centro
CK = fftshift( fft(x) );

% Normaliza os coeficientes da FFT dividindo pelo comprimento do sinal
CK = CK / length(x);


return;

