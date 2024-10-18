library ieee;
use ieee.std_logic_1164.all;

entity flags is
	port (
		A3, B3, iCBo, R3: std_logic;
		CBo, OV: out std_logic
	);
end flags;

architecture flags_logic of flags is
begin
    CBo <= iCBo;
	 OV <= (A3 and B3 and not R3) or (not A3 and not B3 and R3);
end architecture;