#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout	<< BLUE
				<< "Class Cat constructor called\n"
				<< RESET;

	_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout	<< BLUE
				<< "Class Cat copy constructor called\n"
				<< RESET;

	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout	<< BLUE
				<< "Class Cat assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout	<< RED
				<< "Class Cat is destroyed\n"
				<< RESET;

	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout	<< "≽^•⩊•^≼ Meow-meow\n\n";
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}