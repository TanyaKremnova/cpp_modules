#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout	<< BLUE
				<< "Class ScavTrap "
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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout	<< BLUE
				<< "Class ScavTrap "
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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout	<< BLUE
				<< "Class ScavTrap copy constructor called\n"
				<< RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout	<< BLUE
				<< "Class ScavTrap assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout	<< RED
				<< "Class ScavTrap "
				<< _name
				<< " is destroyed\n"
				<< RESET;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout	<< "ScavTrap "
					<< _name
					<< " has no hit points and/or no energy points\n";
		return;
	}

	std::cout	<< "ScavTrap "
				<< _name
				<< " attacks "
				<< target
				<< " causing "
				<< _attackDamage
				<< " points of damage!\n";

	_energyPoints--;
	std::cout	<< "ScavTrap "
				<< _name
				<< " has "
				<< _energyPoints
				<< " energy points after attack\n";
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap "
				<< _name
				<< " is now in Gate keeper mode\n";
}