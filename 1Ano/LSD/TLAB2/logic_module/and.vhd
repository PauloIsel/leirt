library ieee;
use ieee.std_logic_1164.all;

entity logicand is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0)
	);
end logicand;

architecture logicand_logic of logicand is
begin
   R <= A and B;
end architecture;