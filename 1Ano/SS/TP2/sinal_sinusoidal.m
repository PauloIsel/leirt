function [x, t] = sinal_sinusoidal(A, fo, fase, fs, dur)
  ts = 1/fs; # periodo de amostragem
  t = 0:ts:dur;
  x = A * cos(2*pi*fo*t+fase); # array c/ amostras do sinal coseno
end
