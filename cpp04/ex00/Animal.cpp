#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout	<< BLUE
				<< "Class Animal constructor called\n"
				<< RESET;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout	<< BLUE
				<< "Class Animal "
				<< _type
				<< " constructor called\n"
				<< RESET;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout	<< BLUE
				<< "Class Animal copy constructor called\n"
				<< RESET;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout	<< BLUE
				<< "Class Animal assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout	<< RED
				<< "Class Animal is destroyed\n"
				<< RESET;
}

void	Animal::makeSound() const
{
	std::cout	<< "..............\n";
}

std::string	Animal::getType() const
{
	return (_type);
}