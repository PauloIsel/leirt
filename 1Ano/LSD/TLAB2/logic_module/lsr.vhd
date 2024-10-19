library ieee;
use ieee.std_logic_1164.all;

entity logiclsr is
	port (
		A: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		Cy: out std_logic
	);
end logiclsr;

architecture logiclsr_logic of logiclsr is
begin
	Cy <= A(0);
   R(0) <= A(1);
	R(1) <= A(2);
	R(2) <= A(3);
	R(3) <= '0';
end architecture;