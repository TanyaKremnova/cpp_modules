#include "Brain.hpp"

Brain::Brain()
{
	std::cout	<< BLUE
				<< "Class Brain constructor called\n"
				<< RESET;
}

Brain::Brain(const Brain &other)
{
	std::cout	<< BLUE
				<< "Class Brain copy constructor called\n"
				<< RESET;
	
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout	<< BLUE
				<< "Class Brain assignment operator called\n"
				<< RESET;

	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout	<< RED
				<< "Class Brain is destroyed\n"
				<< RESET;
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (_ideas[index]);
	return ("");
}