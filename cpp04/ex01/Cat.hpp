#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Brain;

class Cat : public Animal
{
private:
	Brain	*_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void	makeSound() const override; //This function MUST override a virtual function from the base class
	Brain	*getBrain() const;
};

#endif