#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound! (Called via base pointer)
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}

void	test_copy();
void	test_wrong_animal();
void	test_compare();

// int	main()
// {
// 	// test_copy();
// 	// test_wrong_animal();
// 	// test_compare();
// 	return 0;
// }

void	test_copy()
{
	Cat original;
	Cat copy(original);
	Cat assigned;

	assigned = original;

	original.makeSound();
	copy.makeSound();
	assigned.makeSound();
}

void	test_wrong_animal()
{
	const	WrongAnimal* a = new WrongAnimal();
	const	WrongAnimal* c = new WrongCat();

	a->makeSound(); // WrongAnimal sound
	c->makeSound(); // WrongAnimal sound (INTENTIONALLY WRONG)

	delete a;
	delete c;
}

void	test_compare()
{
	std::cout << "\n=== Compare Animal vs WrongAnimal ===\n";

	const	Animal* good = new Cat();
	const	WrongAnimal* bad = new WrongCat();

	good->makeSound(); // Cat sound
	bad->makeSound();  // WrongAnimal sound

	delete good;
	delete bad;
}
