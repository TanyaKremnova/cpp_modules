#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon( const std::string &type );
	~Weapon();

	const std::string	&getType() const;
	void				setType( const std::string &newType );
};

#endif


// const std::string &			>	Returned value is read-only, cannot modify it
// ... getType() const			>	Method does not modify the object
// const std::string &newType	>	Parameter is read-only, passed by reference