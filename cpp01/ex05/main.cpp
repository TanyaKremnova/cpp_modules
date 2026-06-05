#include "Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout	<< std::endl;

	std::cout	<< YELLOW
				<< "DEBUG level\n"
				<< RESET;
	harl.complain("DEBUG");
	std::cout	<< std::endl;

	std::cout	<< YELLOW
				<< "INFO level\n"
				<< RESET;
	harl.complain("INFO");
	std::cout	<< std::endl;

	std::cout	<< YELLOW
				<< "WARNING level\n"
				<< RESET;
	harl.complain("WARNING");
	std::cout	<< std::endl;

	std::cout	<< YELLOW
				<< "ERROR level\n"
				<< RESET;
	harl.complain("ERROR");

	std::cout	<< std::endl;

	return (0);
}