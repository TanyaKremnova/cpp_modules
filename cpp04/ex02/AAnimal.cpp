#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout	<< BLUE
				<< "Class AAnimal constructor called\n"
				<< RESET;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout	<< BLUE
				<< "Class AAnimal "
				<< _type
				<< " constructor called\n"
				<< RESET;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout	<< BLUE
				<< "Class AAnimal copy constructor called\n"
				<< RESET;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout	<< BLUE
				<< "Class AAnimal assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout	<< RED
				<< "Class AAnimal is destroyed\n"
				<< RESET;
}

void	AAnimal::makeSound() const
{
	std::cout	<< "..............\n";
}

std::string	AAnimal::getType() const
{
	return (_type);
}