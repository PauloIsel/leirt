library ieee;
use ieee.std_logic_1164.all;

entity Yor0 is
	port (
		Y: std_logic_vector(3 downto 0);
		R: out std_logic_vector(3 downto 0);
		OPa: std_logic
	);
end Yor0;

architecture Yor0_logic of Yor0 is
signal OPa_vector: std_logic_vector(3 downto 0);

begin
	OPa_vector(3 downto 0) <= (others => OPa);
	R <= OPa_vector and Y;
end architecture;