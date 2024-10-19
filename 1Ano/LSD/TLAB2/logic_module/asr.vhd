library ieee;
use ieee.std_logic_1164.all;

entity logicasr is
	port (
		A: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		Cy: out std_logic
	);
end logicasr;

architecture logicasr_logic of logicasr is
begin
	Cy <= A(0);
   R(0) <= A(1);
	R(1) <= A(2);
	R(2) <= A(3);
	R(3) <= A(3);
end architecture;