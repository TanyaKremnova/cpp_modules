#include "DiamondTrap.hpp"

int	main()
{
	std::cout	<< MAGENTA
				<< "\n=== Basic construction ===\n"
				<< RESET;
	DiamondTrap	dt("Diamondy");

	std::cout	<< MAGENTA
				<< "\n=== Who am I ===\n"
				<< RESET;
	dt.whoAmI();

	std::cout	<< MAGENTA
				<< "\n=== Attack (ScavTrap version) ===\n"
				<< RESET;
	dt.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Losing energy ===\n"
				<< RESET;
	for (int i = 0; i < 99; i++)
		dt.attack("dummy");

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with no energy ===\n"
				<< RESET;
	dt.attack("dummy");
	dt.beRepaired(10);

	std::cout	<< MAGENTA
				<< "\n=== Taking lethal damage ===\n"
				<< RESET;
	dt.takeDamage(500);

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with 0 hit points ===\n"
				<< RESET;
	dt.attack("dummy");
	dt.beRepaired(10);

	std::cout	<< MAGENTA
				<< "\n=== Copy constructor ===\n"
				<< RESET;
	DiamondTrap	copy(dt);
	copy.whoAmI();

	std::cout	<< MAGENTA
				<< "\n=== Assignment operator ===\n"
				<< RESET;
	DiamondTrap	assign;
	assign = dt;
	assign.whoAmI();

	return (0);
}
