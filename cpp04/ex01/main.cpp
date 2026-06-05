#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	return 0;
}

void	test_brain_independence();
void	test_array();
void	test_copy_constructor();
void	test_assignment_operator();

// int	main()
// {
// 	test_brain_independence();
// 	// test_array();
// 	// test_copy_constructor();
// 	// test_assignment_operator();
// 	return (0);
// }

void	test_brain_independence()
{
	Cat	a;
	Cat	b;
	Dog	c;

	a.getBrain()->setIdea(0, "≽^•⩊•^≼ I want food");
	a.getBrain()->setIdea(1, "≽^•⩊•^≼ I want nap");

	b.getBrain()->setIdea(0, "≽^•⩊•^≼ I want to take whole World!!!");
	b.getBrain()->setIdea(1, "≽^•⩊•^≼ I chase dog");

	c.getBrain()->setIdea(0, "૮₍ • ᴥ • ₎ა Feed me!");
	c.getBrain()->setIdea(1, "૮₍ • ᴥ • ₎ა Play with me!");

	std::cout	<< a.getBrain()->getIdea(0)
				<< std::endl;
	std::cout	<< a.getBrain()->getIdea(1)
				<< std::endl;

	std::cout	<< std::endl;

	std::cout	<< b.getBrain()->getIdea(0)
				<< std::endl;
	std::cout	<< b.getBrain()->getIdea(1)
				<< std::endl;

	std::cout	<< std::endl;

	std::cout	<< c.getBrain()->getIdea(0)
				<< std::endl;
	std::cout	<< c.getBrain()->getIdea(1)
				<< std::endl;
}

void	test_array()
{
	Animal	*animals[10];
	int		i = 0;

	while (i < 5)
		animals[i++] = new Dog();

	while (i < 10)
		animals[i++] = new Cat();

	i = 0;
	while (i < 10)
	{
		std::cout	<< animals[i]->getType()
					<< std::endl;
		i++;
	}

	i = 0;
	while (i < 10)
	{
		delete animals[i];
		i++;
	}
}

void	test_copy_constructor()
{
	Cat	original;
	Cat	copy(original);

	original.getBrain()->setIdea(0, "Original idea");
	copy.getBrain()->setIdea(0, "Copy idea");

	std::cout	<< "Original Cat: "
				<< original.getBrain()->getIdea(0)
				<< std::endl;

	std::cout	<< "Copy Cat: "
				<< copy.getBrain()->getIdea(0)
				<< std::endl;
}

void	test_assignment_operator()
{
	Cat	a;
	Cat	b;

	a.getBrain()->setIdea(0, "Cat A idea");
	b.getBrain()->setIdea(0, "Cat B idea");

	b = a;

	b.getBrain()->setIdea(0, "Modified after assignment");

	std::cout	<< "A: "
				<< a.getBrain()->getIdea(0)
				<< std::endl;
	std::cout	<< "B: "
				<< b.getBrain()->getIdea(0)
				<< std::endl;
}