#include "Zombie.hpp"

// Create a new zombie on the heap, set its name, and give the caller the pointer.
// Zombie* newZombie(name)
// creates a Zombie on the heap
// caller must delete it
// zombie survives after the function ends
// (“long-lived zombie”)
Zombie*	newZombie( std::string name )
{
	Zombie *z = new Zombie(name);

	return (z);
}