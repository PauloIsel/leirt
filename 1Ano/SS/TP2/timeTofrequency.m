%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Informática, Redes e Telecomunicações
%
% SS  - Sinais e Sistemas
%
%
% timeTofreqqunecy.m
% Calcula os coeficientes CK do sinal x com base na função fft() do MATLAB
% Recebe:
%       x, sinal no domínio do tempo.
%       Fs, frequência de amostragem do sinal x.
% Retorna:
%       freq, eixo da frequência
%       CK, valores dos coeficientes CK.

function [freq, CK] = timeTofrequency( x, Fs )


% Calcula o eixo da frequência
freq = ((0 : 1 : length(x)-1)*Fs / ( length(x) )) - Fs/2;

% Espectro.
% Calcula a Transformada Rápida de Fourier (FFT) do sinal x e desloca a componente de frequência zero para o centro
CK = fftshift( fft(x) );

% Normaliza os coeficientes da FFT dividindo pelo comprimento do sinal
CK = CK / length(x);


return;

