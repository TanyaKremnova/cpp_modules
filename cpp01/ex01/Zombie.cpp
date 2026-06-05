#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string n ) : name(n) {}

Zombie::~Zombie()
{
	std::cout	<< "Zombi "
				<< name
				<< " destroyed\n";
}

// REFERENCE TYPE → & in a function parameter (compile time)
// reference (alias) = automatic pointer alias, cannot be null, no *
// Runtime: it behaves like a pointer with automatic dereference
// Compile time: it behaves like an alias to another variable

// A reference refers to the same variable, but:
// you cannot see its address
// you cannot reassign it
// you cannot make it NULL
// you treat it like a normal variable

void	Zombie::setName(const std::string &s)
{
	this->name = s; // performing string assignment, not copying memory addresses.
}

void	Zombie::announce( void )
{
	std::cout	<< RED
				<< name
				<< ": BraiiiiiiinnnzzzZ...\n"
				<< RESET;
}