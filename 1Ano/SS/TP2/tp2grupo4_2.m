clear all
close all
clc

d = 0.5;
f0 = 500;
N = 41;
Fs = 32000;

[x_st, t_st] = myTriangularWave(d, N, f0, Fs);

figure;
subplot(2, 3, 1);
plot(t_st, x_st);
title('Sinal Triangular - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

[freq_st, CK_st] = timeTofrequency(x_st, Fs);

subplot(2, 3, 4);
plot(freq_st, abs(CK_st));
title('Sinal Triangular - Frequência');
xlabel('Frequência (Hz)');
ylabel('|X(f)|');

fcorte_LPF = 600;
H_LPF = Low_Pass_Filter(freq_st, fcorte_LPF);
CK_st_LPF = CK_st .* H_LPF;
[t_y_st_LPF, y_st_LPF] = frequencyToTime(CK_st_LPF, Fs);

subplot(2, 3, 2);
plot(t_y_st_LPF, y_st_LPF);
title('Sinal Triangular (Passa-Baixo) - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(2, 3, 5);
plot(freq_st, abs(CK_st_LPF));
title('Sinal Triangular (Passa-Baixo) - Frequência');
xlabel('Frequência (Hz)');
ylabel('|Y(f)|');

fcorte_HPF = 10000;
H_HPF = High_Pass_Filter(freq_st, fcorte_HPF);
CK_st_HPF = CK_st .* H_HPF;
[t_y_st_HPF, y_st_HPF] = frequencyToTime(CK_st_HPF, Fs);

subplot(2, 3, 3);
plot(t_y_st_HPF, y_st_HPF);
title('Sinal Triangular (Passa-Alto) - Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(2, 3, 6);
plot(freq_st, abs(CK_st_HPF));
title('Sinal Triangular (Passa-Alto) - Frequência');
xlabel('Frequência (Hz)');
ylabel('|Y(f)|');
