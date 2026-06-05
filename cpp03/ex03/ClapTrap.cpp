#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
		: _name("Default"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout	<< BLUE
				<< "Class ClapTrap "
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

ClapTrap::ClapTrap(std::string name)
		: _name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0)
{
	std::cout	<< BLUE
				<< "Class ClapTrap "
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

ClapTrap::ClapTrap(const ClapTrap &other)
		: _name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage)
{
	std::cout	<< BLUE
				<< "Class ClapTrap copy constructor called\n"
				<< RESET;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout	<< BLUE
				<< "Class ClapTrap assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout	<< RED
				<< "Class ClapTrap "
				<< _name
				<< " is destroyed\n"
				<< RESET;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout	<< "ClapTrap "
					<< _name
					<< " has no hit points and/or no energy points\n";
		return;
	}

	std::cout	<< "ClapTrap "
				<< _name
				<< " attacks "
				<< target
				<< " causing "
				<< _attackDamage
				<< " points of damage!\n";

	_energyPoints--;
	std::cout	<< "ClapTrap "
				<< _name
				<< " has "
				<< _energyPoints
				<< " energy points after attack\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout	<< "ClapTrap "
					<< _name
					<< " has no hit points\n";
		return;
	}

	if (amount >= static_cast<unsigned int>(_hitPoints))
	{
		_hitPoints = 0;
		std::cout	<< "RIP... ClapTrap "
					<< _name
					<< " has no more hit points\n";
	}
	else
	{
		_hitPoints = _hitPoints - amount;
		std::cout	<< "ClapTrap "
					<< _name
					<< " took "
					<< amount
					<< " damage and has "
					<< _hitPoints
					<< " hit points remaining\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout	<< "In the beRepaired(). ClapTrap "
					<< _name
					<< " has no hit points and/or no energy points\n";
		return;
	}

	_hitPoints = _hitPoints + amount;
	_energyPoints--;
	std::cout	<< "ClapTrap "
				<< _name
				<< " has "
				<< _hitPoints
				<< " hit points and "
				<< _energyPoints
				<< " energy points\n";
}