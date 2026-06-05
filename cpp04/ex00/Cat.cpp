#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout	<< BLUE
				<< "Class Cat constructor called\n"
				<< RESET;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout	<< BLUE
				<< "Class Cat copy constructor called\n"
				<< RESET;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout	<< BLUE
				<< "Class Cat assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout	<< RED
				<< "Class Cat is destroyed\n"
				<< RESET;
}

void	Cat::makeSound() const
{
	std::cout	<< "≽^•⩊•^≼ Meow-meow\n\n";
}