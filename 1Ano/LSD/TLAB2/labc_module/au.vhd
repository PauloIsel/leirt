library ieee;
use ieee.std_logic_1164.all;

entity au is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		
		CBi, OPau: std_logic;
		CBo, OV: out std_logic
	);
end au;

architecture au_logic of au is
component adder_sub is
	port (
		A, B: std_logic_vector(3 downto 0);
		S: out std_logic_vector(3 downto 0);
		
		Ci, OPau: std_logic;
		Co, b3: out std_logic
	);
end component;

component flags is
	port (
		A3, B3, iCBo, R3: std_logic;
		CBo, OV: out std_logic
	);
end component;

signal b_3, iCBo: std_logic;
signal s_out: std_logic_vector(3 downto 0);
	
begin
	 R <= s_out;

    U1: adder_sub port map(
		A => A,
		B => B,
		OPau => OPau,
		Ci => CBi,
		Co => iCBo,
		b3 => b_3,
		S => s_out
	);
	
	U2: flags port map(
		A3 => A(3),
		B3 => b_3,
		iCBo => iCBo,
		R3 => s_out(3),
		OV => OV,
		CBo => CBo
	);
end architecture;