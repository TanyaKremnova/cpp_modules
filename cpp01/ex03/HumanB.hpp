// HumanB:
// Does not receive weapon in constructor
// May have a NULL weapon
// Must store the weapon as a pointer (not reference)
// Has a setWeapon() method that assigns pointer

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon; // pointer because HumanB can be unarmed

public:
	HumanB( const std::string &name );
	~HumanB();

	void	attack() const;
	void	setWeapon( Weapon &weapon);
};

#endif
