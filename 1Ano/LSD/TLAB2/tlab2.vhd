library ieee;
use ieee.std_logic_1164.all;

entity tlab2 is
	port (
		X, Y: std_logic_vector(3 downto 0);
		OP: std_logic_vector(2 downto 0);
		R: out std_logic_vector(3 downto 0);
		
		CBi: std_logic;
		CBo, OV, Z, GE, BE: out std_logic
	);
end tlab2;

architecture tlab2_logic of tlab2 is
component au is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		
		CBi, OPau: std_logic;
		CBo, OV: out std_logic
	);
end component;

component logic_module is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		
		S0, S1: std_logic;
		Cy: out std_logic
	);
end component;

component mux4 is
	port (
			A, B: std_logic_vector(3 downto 0);
			S: std_logic;
         R: out std_logic_vector(3 downto 0)
	 );
end component;

component decoder is
	port (
		OP: std_logic_vector (2 downto 0);
		OPa, OPb, OPc, OPd, OPe, OPf: out std_logic
	);
end component;

component Yor0 is
	port (
		Y: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		OPa: std_logic
	);
end component;

component flags_main is
	port (
		R: std_logic_vector(3 downto 0);
		iOV, iCB, OP, CY: std_logic;
		
		BE, oGE, Z, oOV, oCB: out std_logic
	);
end component;

signal OPaS, OPbS, OPcS, OPdS, OPeS, OPfS: std_logic;

signal inAu: std_logic_vector(3 downto 0);
signal outAu, outLogic: std_logic_vector(3 downto 0);

signal auOV, auCBo, logicCY: std_logic;

signal outMUX: std_logic_vector(3 downto 0);

begin
	R <= outMUX;

	Decode: decoder port map(
		OP => OP,
		OPa => OPaS, 
		OPb => OPbS,
		OPc => OPcS,
		OPd => OPdS,
		OPe => OPeS, 
		OPf => OPfS
	);
	
	U1_B: Yor0 port map(
		Y => Y,
		OPa => OPaS,
		R => inAu
	);

	U1: au port map(
		A => X,
		B => inAu,
		CBi => CBi,
		OPau => OPbS,
		R => outAu,
		OV => auOV,
		CBo => auCBo
	);
	
	U2: logic_module port map(
		A => X,
		B => Y,
		S0 => OPdS,
		S1 => OPeS,
		R => outLogic,
		CY => logicCY
	);
	
	U3: mux4 port map(
		A => outAu,
		B => outLogic,
		R => outMUX,
		S => OPcS
	);
	
	U4: flags_main port map(
		iOV => auOV,
		iCB => auCBo,
		OP => OPfS,
		R => outMUX,
		CY => logicCY,
		BE => BE,
		oGE => GE,
		Z => Z,
		oOV => OV,
		oCB => CBo
	);
end architecture;