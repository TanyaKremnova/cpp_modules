// HumanA:
// Always has a weapon
// Constructor receives a Weapon by reference
// Stores the Weapon as a reference
// Because of that, changes to the weapon update HumanA automatically

// _name → class member
// name → parameter

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon		&_weapon; // A reference because HumanA is always armed

public:
	HumanA( const std::string &name, Weapon &weapon);
	~HumanA();

	void	attack() const;
};

#endif