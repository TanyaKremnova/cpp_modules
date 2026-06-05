#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string given_name )
{
	if (N <= 0 || given_name.empty())
		return (NULL);

	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(given_name);
	
	return (zombies);
}