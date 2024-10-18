library ieee;
use ieee.std_logic_1164.all;

entity flags_main is
	port (
		R: std_logic_vector(3 downto 0);
		iOV, iCB, OP, CY: std_logic;
		
		BE, oGE, Z, oOV, oCB: out std_logic
	);
end flags_main;

architecture flags_main_logic of flags_main is
signal zero: std_logic;

begin
	zero <= not (R(0) or R(1) or R(2) or R(3));
	
	Z <= zero;
	oGE <= (not zero and not R(3) and not iOV) or (R(3) and iOV) or (zero and not iOV);
	BE <= iCB or zero;
	oOV <= iOV;
	oCB <= (not OP and CY) or (OP and ICB);
end architecture;