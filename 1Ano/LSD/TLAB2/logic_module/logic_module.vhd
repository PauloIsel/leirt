library ieee;
use ieee.std_logic_1164.all;

entity logic_module is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		
		S0, S1: std_logic;
		Cy: out std_logic
	);
end logic_module;

architecture logic_module_logic of logic_module is
component logiclsr is
	port (
			A: std_logic_vector(3 downto 0);
         R: out std_logic_vector(3 downto 0);
			Cy: out std_logic
	 );
end component;

component logicasr is
	port (
			A: std_logic_vector(3 downto 0);
         R: out std_logic_vector(3 downto 0);
			Cy: out std_logic
	 );
end component;

component logicor is
	port (
			A, B: std_logic_vector(3 downto 0);
         R: out std_logic_vector(3 downto 0)
	 );
end component;

component logicand is
	port (
			A, B: std_logic_vector(3 downto 0);
         R: out std_logic_vector(3 downto 0)
	 );
end component;

signal outLSR, outASR, outOR, outAND: std_logic_vector(3 downto 0);
signal outCyLSR, outCyASR: std_logic;
signal s0_vector, s1_vector: std_logic_vector(3 downto 0);

begin
	s0_vector(3 downto 0) <= (others => S0);
	s1_vector(3 downto 0) <= (others => S1);

	R <= (not s0_vector and not s1_vector and outLSR) or (not s0_vector and s1_vector and outASR) or (s0_vector and not s1_vector and outOR) or (s0_vector and s1_vector and outAND); 
	Cy <= (not S0 and not S1 and outCyLSR) or (not S0 and S1 and outCyASR);

	U1: logiclsr port map(
		A => A,
		R => outLSR,
		Cy => outCyLSR
	);
	
	U2: logicasr port map(
		A => A,
		R => outASR,
		Cy => outCyASR
	);
	
	U3: logicor port map(
		A => A,
		B => B,
		R => outOR
	);
	
	U4: logicand port map(
		A => A,
		B => B,
		R => outAND
	);
end architecture;