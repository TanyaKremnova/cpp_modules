#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class Brain
{
private:
	std::string	_ideas[100];

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void		setIdea(int index, const std::string &idea);
	std::string	getIdea(int index) const;
};

#endif