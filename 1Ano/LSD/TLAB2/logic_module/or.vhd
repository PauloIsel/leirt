library ieee;
use ieee.std_logic_1164.all;

entity logicor is
	port (
		A, B: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0)
	);
end logicor;

architecture logicor_logic of logicor is
begin
   R <= A or B;
end architecture;