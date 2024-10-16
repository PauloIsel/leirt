%
% ISEL - Instituto Superior de Engenharia de Lisboa.
%
% LEIRT -  Licenciatura em Engenharia Inform�tica, Redes e Telecomunica��es
%
% SS  - Sinais e Sistemas
%
%
% Low_Pass_Filter.m
% Determina a fun��o de transfer�ncia de um filtro passa baixo de 1�Ordem
% Recebe:
%       freq, eixo das frequ�ncias.
%       fcorte, frequ�ncia de corte.
% Retorna:
%       H_LPF, amostras da fun��o de transfer�ncia


function H_LPF = Low_Pass_Filter (freq, fcorte)

% Filtro em fun�ao da frequencia de corte
  H_LPF=1./(1+j*2*pi*freq/fcorte);

endfunction
