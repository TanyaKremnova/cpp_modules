#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("pink arbalest");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("magic rapier");
		jim.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB tim("Tim");
		// tim.setWeapon(club);
		tim.attack();
		club.setType("broken gun");
		tim.attack();
	}
	return (0);
}