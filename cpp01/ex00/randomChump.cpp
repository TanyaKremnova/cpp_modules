#include "Zombie.hpp"

// void randomChump(name)
// creates a Zombie on the stack
// destroyed automatically when function ends
// (“short-lived zombie”)
void	randomChump( std::string name )
{
	Zombie z(name);
	z.announce();
}