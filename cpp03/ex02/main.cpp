#include "FragTrap.hpp"

int	main()
{
	FragTrap	ft("Fraggy");

	std::cout	<< MAGENTA
				<< "\n=== High fives ===\n"
				<< RESET;
	ft.highFivesGuys();

	std::cout	<< MAGENTA
				<< "\n=== Basic attack ===\n"
				<< RESET;
	ft.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Taking damage ===\n"
				<< RESET;
	ft.takeDamage(40);

	std::cout	<< MAGENTA
				<< "\n=== Repairing ===\n"
				<< RESET;
	ft.beRepaired(20);

	std::cout	<< MAGENTA
				<< "\n=== Losing energy ===\n"
				<< RESET;
	
	// Attack repeatedly until energy is 0
	for (int i = 0; i < 99; i++)
		ft.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with no energy ===\n"
				<< RESET;
	ft.attack("target_dummy");
	ft.beRepaired(10);

	std::cout	<< MAGENTA
				<< "\n=== Taking lethal damage ===\n"
				<< RESET;
	ft.takeDamage(200);

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with 0 hit points ===\n"
				<< RESET;
	ft.attack("target_dummy");
	ft.beRepaired(10);
	
	return (0);
}
