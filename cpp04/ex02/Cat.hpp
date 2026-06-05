#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Brain;

class Cat : public AAnimal
{
private:
	Brain	*_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void	makeSound() const override;
	Brain	*getBrain() const;
};

#endif