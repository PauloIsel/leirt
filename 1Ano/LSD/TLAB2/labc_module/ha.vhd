library ieee;
use ieee.std_logic_1164.all;

entity ha is
	port (
		A, B: std_logic;
		S, Co: out std_logic
	);
end ha;

architecture ha_logic of ha is
begin
    S <= A xor B;
	 Co <= A and B;
end architecture;