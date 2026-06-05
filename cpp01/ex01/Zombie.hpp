#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#  define RED "\033[3;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	name;

public:
	Zombie();
	Zombie( std::string n );
	~Zombie();

	void	setName(std::string const &s);
	void	announce( void );
};

	Zombie*	zombieHorde( int N, std::string name );

#endif