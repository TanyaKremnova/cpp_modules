#include "Zombie.hpp"

int	main( void )
{
	int		N = 5;

	Zombie	*horde = zombieHorde(N, "Foo");
	if (!horde)
		return (EXIT_FAILURE);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;

	return (EXIT_SUCCESS);
}
