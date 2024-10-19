clear all
close all
clc

pkg load communications

%inicializacoes
%sinal de entrada

Mmax = 1;
fm = 513;
fase = -pi / 2;
fs = 8000;
T = 1;

%Quantificador
R = 4;
flag = 'dpcm_mr';
V = Mmax;

m = oscilador(Mmax, fm, fase, fs, T);
#m = audioread('joa_nor.wav');

P = mean(m.*m);
R1 = mean(m(1:end -1) .* m(2:end));
r1 = R1 / P
##r1 = cos(2*pi*fm/fs)
##a1 = 0; %alinea i
a1 = r1; %alinea h
##a1 = 1; %preditor unitario
Gp = 1 / (1+a1*a1-2*a1*r1)
V1 = sqrt(V.^2 / Gp)


[vd, vq] = tabelas(V1, R, flag)

mq = zeros(size(m));
mpT = 0;
mpR = 0;

for amostra = 1 : length(m)
  [Tbits, mpT] = CoderDPCM(m(amostra), mpT, vd, vq, a1);
  Rbits = Tbits;
  [mq(amostra), mpR] = DecoderDPCM(Rbits, mpR, vq, a1);
end
mq(1:8)

nerros = 0;

for amostra = 1 : length(m)
 [Tbits, mpT] = CoderDPCM(m(amostra), mpT, vd, vq, a1);
 CLt = Manchester(Tbits, A, Tb);
 CLr = CanalAWGN(CLt, AtdB, PrdBW);
 Rbits = RO(CLr, c, lambda);
 [mq(amostra), mpR] = DecoderDPCM(Rbits, mpR, vq, a1);
 nerros = nerros+sum(xor(Tbits, Rbits));
end

SNRt = 6.02 * R + 10 * log10(3*P/V1.^2)
SNRr = SNRreal(m, mq)
Qerror = m-mq;

figure
plot(Qerror);
##
##figure
##plot(m)
##hold on
##plot (mq, 'r')
##plot (Qerror, 'k')
