library ieee;
use ieee.std_logic_1164.all;

entity adder_sub is
	port (
		A, B: std_logic_vector(3 downto 0);
		S: out std_logic_vector(3 downto 0);
		
		Ci, OPau: std_logic;
		Co, b3: out std_logic
	);
end adder_sub;

architecture adder_sub_logic of adder_sub is
component adder is
	port (
		A, B: std_logic_vector(3 downto 0);
		S: out std_logic_vector(3 downto 0);
		
		Ci: std_logic;
		Co: out std_logic
	);
end component;

signal bt, opau_vector: std_logic_vector(3 downto 0);
signal Cit, Cot: std_logic;

begin
	opau_vector(3 downto 0) <= (others => OPau);
	bt <= B xor opau_vector;
	
	Cit <= Ci xor OPau;
	Co <= Cot xor OPau;
	
	b3 <= B(3) xor Opau;

	U1: adder port map(
		A => A,
		B => bt,
		Ci => Cit,
		Co => Cot,
		S => S
	);
end architecture;