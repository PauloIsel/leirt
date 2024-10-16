clear all
close all
clc

Fs = 8000;

% a
t = -10:1/Fs:10;

x = 4 * (1 - abs(t/4)) .* (abs(t) <= 4);
h = 2 * (abs(t-2) <= 2);
y = conv(x, h, 'same');

figure;
subplot(3,1,1);
plot(t, x);
title('Sinal x(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(3,1,2);
plot(t, h);
title('Sinal h(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(3,1,3);
plot(t, y);
title('Sinal y(t) = x(t) * h(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');


% b
n = 0:4;
x = 0.5.^n;
h = ones(1, length(n));
y = conv(x, h)(1:5);

disp('As cinco primeiras amostras do sinal de saída y[n]:');
disp(y);

% c
x = 4 + 2*cos(2*pi*500*t) + 4*cos(2*pi*1500*t) + 8*cos(2*pi*2500*t);
h = 16000 * sinc(4000 * t);

% ii
[freq_x, CK_x] = timeTofrequency(x, Fs);
[freq_h, CK_h] = timeTofrequency(h, Fs);

figure;
subplot(2,1,1);
plot(freq_x, abs(CK_x));
title('Espetro de Amplitude - x(t)');
xlabel('Frequência (Hz)');
ylabel('|X(f)|');

subplot(2,1,2);
plot(freq_h, abs(CK_h));
title('Espetro de Amplitude - h(t)');
xlabel('Frequência (Hz)');
ylabel('|H(f)|');

% iii
CK_y = CK_x .* CK_h;
[t, y] = frequencyToTime(CK_y, Fs);

figure;
plot(t, y);
title('Sinal y(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');
