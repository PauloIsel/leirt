library ieee;
use ieee.std_logic_1164.all;

entity mux4 is
    port (
			A, B: in std_logic_vector(3 downto 0);
			S: in std_logic;
         R: out std_logic_vector(3 downto 0)
	 );
end mux4;

architecture mux4_logic of mux4 is
signal sel: std_logic_vector(3 downto 0);

begin
	sel(3 downto 0) <= (others => S);
	R <= (sel and A) or (not sel and B);
end architecture;
