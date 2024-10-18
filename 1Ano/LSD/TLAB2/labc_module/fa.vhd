library ieee;
use ieee.std_logic_1164.all;

entity fa is
	port (
		A, B, Ci: std_logic;
		S, Co: out std_logic
	);
end fa;

architecture fa_logic of fa is
component ha is
	port (
		A, B: std_logic;
		S, Co: out std_logic
	);
end component;

signal addAB: std_logic;
signal carry: std_logic_vector(1 downto 0);

begin
    U1: ha port map(
		A => A,
		B => B,
		S => addAB,
		Co => carry(0)
	);
	
	U2: ha port map(
		A => addAB,
		B => Ci,
		S => S,
		Co => carry(1)
	);
	
	Co <= carry(0) or carry(1);
end architecture;