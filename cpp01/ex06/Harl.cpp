#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!\n";
}

void	Harl::info( void )
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! If you did, "
				<< "I wouldn’t be asking for more!\n";
}

void	Harl::warning( void )
{
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years, whereas you started working "
				<< "here just last month.\n";
}

void	Harl::error( void )
{
	std::cout	<< "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level ) // lookup table (a manual dictionary)
{

	static const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	static void (Harl::*actions[4])() = {
	actions[0] = &Harl::debug,
	actions[1] = &Harl::info,
	actions[2] = &Harl::warning,
	actions[3] = &Harl::error,
	};

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*actions[i])(); // this-> — call a method on THIS object
			return;
		}
	}
}

// Table of member-function pointers:
// return_type (ClassName:: *name)(argument_list)