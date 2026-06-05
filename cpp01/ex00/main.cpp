#include "Zombie.hpp"

int	main( void )
{
	Zombie *z = newZombie("HeapZombie");
	z->announce();
	delete(z);

	randomChump("StackZombie");

	return (0);
}

// Stack vs Heap

// ✔ Stack
// - Automatic storage.
// - Variables disappear when the function ends.
// - Fast, safe, no manual deletion.

// ✔ Heap
// - Manual or smart-pointer-controlled storage.
// - Lives until you delete it (or until smart pointer deletes it).
// - Slower, but flexible when you need long-living objects.