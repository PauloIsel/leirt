library ieee;
use ieee.std_logic_1164.all;

entity adder is
	port (
		A, B: std_logic_vector(3 downto 0);
		S: out std_logic_vector(3 downto 0);
		
		Ci: std_logic;
		Co: out std_logic
	);
end adder;

architecture adder_logic of adder is
component fa is
	port (
		A, B, Ci: std_logic;
		S, Co: out std_logic
	);
end component;

signal carry: std_logic_vector(3 downto 1);

begin
    U1: fa port map(
		A => A(0),
		B => B(0),
		Ci => Ci,
		S => S(0),
		Co => carry(1)
	);
	
	U2: fa port map(
		A => A(1),
		B => B(1),
		Ci => carry(1),
		S => S(1),
		Co => carry(2)
	);
	
	U3: fa port map(
		A => A(2),
		B => B(2),
		Ci => carry(2),
		S => S(2),
		Co => carry(3)
	);
	
	U4: fa port map(
		A => A(3),
		B => B(3),
		Ci => carry(3),
		S => S(3),
		Co => Co
	);
end architecture;