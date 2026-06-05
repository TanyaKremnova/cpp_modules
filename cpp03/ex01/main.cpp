#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	st("Scavvy");

	std::cout	<< MAGENTA
				<< "\n=== Guard Gate mode ===\n"
				<< RESET;
	st.guardGate();

	std::cout	<< MAGENTA
				<< "\n=== Basic attack ===\n"
				<< RESET;
	st.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Taking damage ===\n"
				<< RESET;
	st.takeDamage(30);

	std::cout	<< MAGENTA
				<< "\n=== Repairing ===\n"
				<< RESET;
	st.beRepaired(20);

	std::cout	<< MAGENTA
				<< "\n=== Losing energy ===\n"
				<< RESET;
	
	// Attack repeatedly until energy is 0
	for (int i = 0; i < 50; i++)
		st.attack("target_dummy");

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with no energy ===\n"
				<< RESET;
	st.attack("target_dummy");
	st.beRepaired(5);

	std::cout	<< MAGENTA
				<< "\n=== Taking lethal damage ===\n"
				<< RESET;
	st.takeDamage(200);

	std::cout	<< MAGENTA
				<< "\n=== Trying to act with 0 hit points ===\n"
				<< RESET;
	st.attack("target_dummy");
	st.beRepaired(5);
	
	return (0);
}
