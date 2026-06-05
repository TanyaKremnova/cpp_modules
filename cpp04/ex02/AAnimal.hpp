#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class AAnimal // Abstract class (A class is abstract if it has at least one pure virtual function)
{
protected:
	std::string	_type;

public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;	// " = 0" makes function pure virtual
											// class becomes abstract and cannot be instantiated
	std::string		getType() const;
};

#endif
