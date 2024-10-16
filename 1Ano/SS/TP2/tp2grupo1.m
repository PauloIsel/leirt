close all
clear all
clc

A = 5;
fo = 500;
fase = 0;
fs = 16e3;
dur = 400*(1/fo);

[x, t] = sinal_sinusoidal(A, fo, fase, fs, dur);
figure;
plot(t, x, '.-');
grid

[freq, CK] = timeTofrequency( x, fs );
figure;
plot(freq, abs(CK));
grid
