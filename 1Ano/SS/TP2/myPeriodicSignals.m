clear all
close all
clc

fs = 8e3;

A = 1;
d = 0.125;
N = 22;
fo = 100;

[x, t] = mySquareWave(A, d, N, fo);
figure;
subplot(3, 2, 1);
plot(t, x);
title('Onda Quadrada - x(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;

[freq, CK] = timeTofrequency(x, fs);
subplot(3, 2, 3);
plot(freq, abs(CK));
title('Espetro de Amplitude - x(t)');
xlabel('Frequência (Hz)');
ylabel('|X(f)|');
grid on;

subplot(3, 2, 5);
plot(freq, angle(CK)*180/pi);
title('Espetro de Fase - x(t)');
xlabel('Frequência (Hz)');
ylabel('arg(X(f))º');
grid on;

d = 0.125;
N = 22;
fo = 100;

[y, t2] = myTriangularWave(d, N, fo);
subplot(3, 2, 2);
plot(t2, y);
title('Onda Triangular - y(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;

[freq, CK] = timeTofrequency(y, fs);
subplot(3, 2, 4);
plot(freq, abs(CK));
title('Espetro de Amplitude - y(t)');
xlabel('Frequência (Hz)');
ylabel('|Y(f)|');
grid on;

subplot(3, 2, 6);
plot(freq, angle(CK)*180/pi);
title('Espetro de Fase - y(t)');
xlabel('Frequência (Hz)');
ylabel('arg(Y(f))º');
grid on;
