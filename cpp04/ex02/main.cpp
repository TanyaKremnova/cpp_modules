#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	// AAnimal	a;						// ❌ ERROR: cannot instantiate abstract class (compile-time check)
	// AAnimal	*ptr = new AAnimal();	// ❌ ERROR: cannot instantiate abstract class (compile-time check)

	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return (0);
}

