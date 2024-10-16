clear all
close all
clc

A = 10;
d = 0.5;
f0 = 500;
N = 40;
Fs = 32000;

[x_sq, t_sq] = mySquareWave(A, d, N, f0, Fs);

figure;
subplot(2, 3, 1);
plot(t_sq, x_sq);
title('Sinal Quadrado - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

[freq_sq, CK_sq] = timeTofrequency(x_sq, Fs);

subplot(2, 3, 4);
plot(freq_sq, abs(CK_sq));
title('Sinal Quadrado - Frequência');
xlabel('Frequência (Hz)');
ylabel('|X(f)|');

fcorte_LPF = 600;
H_LPF = Low_Pass_Filter(freq_sq, fcorte_LPF);
CK_sq_LPF = CK_sq .* H_LPF;
[t_y_sq_LPF, y_sq_LPF] = frequencyToTime(CK_sq_LPF, Fs);

subplot(2, 3, 2);
plot(t_y_sq_LPF, y_sq_LPF);
title('Sinal Quadrado (Passa-Baixo) - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(2, 3, 5);
plot(freq_sq, abs(CK_sq_LPF));
title('Sinal Quadrado (Passa-Baixo) - Frequência');
xlabel('Frequência (Hz)');
ylabel('|Y(f)|');

fcorte_HPF = 10000;
H_HPF = High_Pass_Filter(freq_sq, fcorte_HPF);
CK_sq_HPF = CK_sq .* H_HPF;
[t_y_sq_HPF, y_sq_HPF] = frequencyToTime(CK_sq_HPF, Fs);

subplot(2, 3, 3);
plot(t_y_sq_HPF, y_sq_HPF);
title('Sinal Quadrado (Passa-Alto) - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(2, 3, 6);
plot(freq_sq, abs(CK_sq_HPF));
title('Sinal Quadrado (Passa-Alto) - Frequência');
xlabel('Frequência (Hz)');
ylabel('|Y(f)|');
