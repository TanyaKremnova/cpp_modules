#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout	<< GREEN
					<< "\n* * * Test: Normal construction * * *\n"
					<< RESET;

		Bureaucrat	bob("Bob", 42);

		std::cout	<< bob
					<< std::endl
					<< std::endl;
	}

	{
		std::cout	<< GREEN
					<< "* * * Test: Boundary construction * * *\n"
					<< RESET;

		Bureaucrat	top_lvl("Alice", 1);
		Bureaucrat	low_lvl("Charlie", 150);

		std::cout	<< top_lvl
					<< std::endl;
		std::cout	<< low_lvl
					<< std::endl
					<< std::endl;
	}

	{
		std::cout	<< RED
					<< "* * * Test: Exceptions * * *\n"
					<< RESET;

		try
		{
			Bureaucrat	tooHighGrade("Guy1", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	tooLowGrade("Guy2", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	negativeGrade("Guy3", -1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout	<< YELLOW
					<< "* * * Test: incrementGrade / decrementGrade * * *\n"
					<< RESET;

		Bureaucrat	bob("Bob", 42);
		std::cout	<< bob
					<< std::endl;
		bob.incrementGrade();
		std::cout	<< "After incrementGrade() "
					<< bob
					<< std::endl;
		bob.decrementGrade();
		std::cout	<< "After decrementGrade() "
					<< bob
					<< std::endl
					<< std::endl;

		try
		{
			Bureaucrat	top_lvl("Alice", 1);
			std::cout	<< top_lvl
						<< std::endl;
			std::cout	<< "After incrementGrade()\n";
			top_lvl.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}

		try
		{
			Bureaucrat	low_lvl("Charlie", 150);
			std::cout	<< low_lvl
						<< std::endl;
			std::cout	<< "After decrementGrade()\n";
			low_lvl.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}

	return (0);
}