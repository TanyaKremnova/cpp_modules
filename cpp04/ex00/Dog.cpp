#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout	<< BLUE
				<< "Class Dog constructor called\n"
				<< RESET;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout	<< BLUE
				<< "Class Dog copy constructor called\n"
				<< RESET;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout	<< BLUE
				<< "Class Dog assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout	<< RED
				<< "Class Dog is destroyed\n"
				<< RESET;
}

void	Dog::makeSound() const
{
	std::cout	<< "૮₍ • ᴥ • ₎ა Woof-woof\n\n";
}