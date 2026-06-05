#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Please provide: ./sed filename s1 s2\n";
		return (EXIT_FAILURE);
	}

	Sed	sed(argv[1], argv[2], argv[3]);
	if (!sed.process())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}