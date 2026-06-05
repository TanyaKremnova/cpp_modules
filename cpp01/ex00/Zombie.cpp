#include "Zombie.hpp"

// : name(n) - “Set name to n before the constructor body runs”
Zombie::Zombie( std::string n ) : name(n) {}

Zombie::~Zombie()
{
	std::cout	<< "Zombi "
				<< name
				<< " destroyed\n";
}

void	Zombie::announce( void )
{
	std::cout	<< RED
				<< name
				<< ": BraiiiiiiinnnzzzZ...\n"
				<< RESET;
}