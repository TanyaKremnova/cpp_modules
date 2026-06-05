#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout	<< BLUE
				<< "Class FragTrap "
				<< _name
				<< " constructor called\n"
				<< RESET;
	std::cout	<< CYAN
				<< _name
				<< " has "
				<< _hitPoints
				<< " hit points, "
				<< _energyPoints
				<< " energy points and can attack with "
				<< _attackDamage
				<< " attack damage points\n"
				<< RESET;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout	<< BLUE
				<< "Class FragTrap "
				<< _name
				<< " constructor called\n"
				<< RESET;
	std::cout	<< CYAN
				<< _name
				<< " has "
				<< _hitPoints
				<< " hit points, "
				<< _energyPoints
				<< " energy points and can attack with "
				<< _attackDamage
				<< " attack damage points\n"
				<< RESET;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout	<< BLUE
				<< "Class FragTrap copy constructor called\n"
				<< RESET;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout	<< BLUE
				<< "Class FragTrap assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout	<< RED
				<< "Class FragTrap "
				<< _name
				<< " is destroyed\n"
				<< RESET;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout	<< "FragTrap "
				<< _name
				<< " requests a positive high five\n";
}