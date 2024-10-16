%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Informática, Redes e Telecomunicações
%
% SS  - Sinais e Sistemas
%
%
% Low_Pass_Filter.m
% Determina a função de transferência de um filtro passa baixo de 1ªOrdem
% Recebe:
%       freq, eixo das frequências.
%       fcorte, frequência de corte.
% Retorna:
%       H_LPF, amostras da função de transferência


function H_LPF = Low_Pass_Filter (freq, fcorte)

% Filtro em funçao da frequencia de corte
  H_LPF=1./(1+j*2*pi*freq/fcorte);

endfunction
