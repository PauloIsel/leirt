library ieee;
use ieee.std_logic_1164.all;

entity decoder is
	port (
		OP: std_logic_vector (2 downto 0);
		OPa, OPb, OPc, OPd, OPe, OPf: out std_logic
	);
end decoder;

architecture decoder_logic of decoder is

-- 0 0 0, OPd = 0 OPe = 0 
-- 0 0 1, OPd = 0 OPe = 1 
-- 0 1 0 , OPd = 1 OPe = 0
-- 0 1 1 , OPd = 1 OPe = 1

begin
	OPa <= OP(1);
	OPb <= OP(0);
	OPc <= OP(2);
	OPd <= OP(1);
	OPe <= OP(0);
	OPf <= OP(2);
end architecture;