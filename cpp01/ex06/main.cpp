#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	int			index = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (EXIT_FAILURE);

	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			index = i;
	}

	switch (index)
	{
	case 0:
		std::cout	<< MAGENTA
					<< "[ DEBUG ]\n"
					<< RESET;
		harl.complain("DEBUG");
	case 1:
		std::cout	<< MAGENTA
					<< "[ INFO ]\n"
					<< RESET;
		harl.complain("INFO");
	case 2:
		std::cout	<< MAGENTA
					<< "[ WARNING ]\n"
					<< RESET;
		harl.complain("WARNING");
	case 3:
		std::cout	<< MAGENTA
					<< "[ ERROR ]\n"
					<< RESET;
		harl.complain("ERROR");
		break;
	default:
		std::cout	<< YELLOW
					<< "[ Probably complaining about insignificant problems ]\n"
					<< RESET;
		break;
	}
	return (EXIT_SUCCESS);
}