#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout	<< BLUE
				<< "Class WrongCat constructor called\n"
				<< RESET;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout	<< BLUE
				<< "Class WrongCat copy constructor called\n"
				<< RESET;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout	<< BLUE
				<< "Class WrongCat assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout	<< RED
				<< "Class WrongCat is destroyed\n"
				<< RESET;
}

void	WrongCat::makeSound() const
{
	std::cout	<< "≽^•⩊•^≼ Wrong-Wrong\n\n";
}