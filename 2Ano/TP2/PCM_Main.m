clear all
close all
clc

pkg load communications

#Variaveis globais
Mmax = 1; #amplitude máxima da sinusoide
fsin= 1327; #frequência máxima da sinusoide
fase = 0;
fs = 8000; #frequência de amostragem
T = 1;
A = 87.56;

V = Mmax;
R = 8;

flag = 'mr';

m = oscilador(Mmax, fsin, fase, fs, T);
m = 0.5 * m;
##m = audioread('car_nor.wav');
##m = -1 + 2*rand(1,10000);

[vd, vq] = tabelas(V, R, flag);

##vd = compand(vd, A, V, 'A/expander')
##vq = compand(vq, A, V, 'A/expander')

##[vd, vq] = lloyds(m,2^R);

mq = zeros(size(m)); # array por preencher com os valores das
                     # amostras da sinusoide descodificada

for amostra = 1 : length(m)
  Tbits = CoderPCM(m(amostra), vd);
  Rbits = Tbits;
  mq(amostra) = DecoderPCM(Rbits, vq);
end

##figure
##hist(m,100)

##for amostra = 1 : length(m)
##  X = compand(m(amostra), A, V, 'A/compressor');
##  Tbits = CoderPCM(X, vd);
##  Rbits = Tbits;
##  Y = DecoderPCM(Rbits, vq);
##  mq(amostra) = compand(Y, A, V, 'A/expander');
##end

P = mean(m.^2)
Qerror = m - mq;
Maxerror= max(abs(Qerror))

SNRt = 6.02 * R + 10 * log10(3*P/V.^2)
##SNRt = 6.02 * R - 10
SNRr = SNRreal(m, mq)

##figure;
##hold on;
##plot(m,mq, '.')
##grid
##
##figure;
##plot(m);
##
##figure;
##plot(mq);
##
##
##figure;
##hist(Qerror, 100)


#Exercicio 4
##
##figure;
##hist(m,100)
##
##mcomp = compand(m, A, V, 'A/compressor');
##
##figure;
##hist(mcomp, 100)
##
##figure;
##plot(m, mcomp, '.')





