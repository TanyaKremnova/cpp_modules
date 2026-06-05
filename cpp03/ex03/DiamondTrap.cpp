#include "DiamondTrap.hpp"

//         ClapTrap
//         /      \
//    ScavTrap   FragTrap
//         \      /
//        DiamondTrap

// Its attributes and member functions will be inherited from its parent classes:
// • Name, which is passed as a parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (ScavTrap)

DiamondTrap::DiamondTrap()
		: ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Diamond";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout	<< BLUE
				<< "Class DiamondTrap "
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

DiamondTrap::DiamondTrap(std::string name)
		: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout	<< BLUE
				<< "Class DiamondTrap "
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
 
DiamondTrap::DiamondTrap(const DiamondTrap &other)
		: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	_name = other._name;

	std::cout	<< BLUE
				<< "Class DiamondTrap copy constructor called\n"
				<< RESET;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout	<< BLUE
				<< "Class DiamondTrap assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< RED
				<< "Class DiamondTrap "
				<< _name
				<< " is destroyed\n"
				<< RESET;
}

void	DiamondTrap::whoAmI()
{
	std::cout	<< "DiamondTrap name: "
				<< _name
				<< std::endl;
	std::cout	<< "ClapTrap name: "
				<< ClapTrap::_name
				<< std::endl;
}