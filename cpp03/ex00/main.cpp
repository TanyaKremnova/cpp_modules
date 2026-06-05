#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ct("Clappy");

	std::cout	<< MAGENTA
				<< "\n=== Basic attack ===\n"
				<< RESET;
	ct.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Taking damage ===\n"
				<< RESET;
	ct.takeDamage(5);

	std::cout	<< MAGENTA
				<< "\n=== Repairing ===\n"
				<< RESET;
	ct.beRepaired(3);

	std::cout	<< MAGENTA
				<< "\n=== Losing energy ===\n"
				<< RESET;
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");
	ct.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with no energy ===\n"
				<< RESET;
	ct.attack("target_dummy");
	ct.beRepaired(5);

	std::cout	<< MAGENTA
				<< "\n=== Taking lethal damage ===\n"
				<< RESET;
	ct.takeDamage(20);

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with 0 hit points ===\n"
				<< RESET;
	ct.attack("target_dummy");
	ct.beRepaired(5);

	return (0);
}
