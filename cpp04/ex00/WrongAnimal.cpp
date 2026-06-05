#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout	<< BLUE
				<< "Class WrongAnimal constructor called\n"
				<< RESET;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout	<< BLUE
				<< "Class WrongAnimal "
				<< _type
				<< " constructor called\n"
				<< RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout	<< BLUE
				<< "Class WrongAnimal copy constructor called\n"
				<< RESET;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout	<< BLUE
				<< "Class WrongAnimal assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< RED
				<< "Class WrongAnimal is destroyed\n"
				<< RESET;
}

void	WrongAnimal::makeSound() const
{
	std::cout	<< "༼つ ◕_◕ ༽つ What does the ᓚᘏᗢ fox say?\n\n";
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}