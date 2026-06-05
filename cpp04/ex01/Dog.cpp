#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout	<< BLUE
				<< "Class Dog constructor called\n"
				<< RESET;

	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout	<< BLUE
				<< "Class Dog copy constructor called\n"
				<< RESET;

	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout	<< BLUE
				<< "Class Dog assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout	<< RED
				<< "Class Dog is destroyed\n"
				<< RESET;

	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout	<< "૮₍ • ᴥ • ₎ა Woof-woof\n\n";
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}