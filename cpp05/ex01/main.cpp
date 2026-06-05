#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout	<< GREEN
					<< "\n* * * Test: Successful signing * * *\n"
					<< RESET;

		Bureaucrat	alice("Alice", 10);
		Form		formA("FormA", 20, 50);

		std::cout	<< alice
					<< std::endl;
		alice.signForm(formA);
		std::cout	<< formA
					<< std::endl
					<< std::endl;
	}

	{
		std::cout	<< RED
					<< "* * * Test: Signing fails (grade too low) * * *\n"
					<< RESET;

		Bureaucrat	bob("Bob", 50);
		Form		formA("FormA", 20, 50);

		std::cout	<< bob
					<< std::endl;
		bob.signForm(formA);
		std::cout	<< formA
					<< std::endl
					<< std::endl;
	}

	{
		std::cout	<< RED
					<< "* * * Test: Invalid form construction * * *\n"
					<< RESET;

		try
		{
			Form	badForm("BadForm", 0, 200);
		}
		catch(const std::exception& e)
		{
			std::cerr	<< "Form creation failed: "
						<< e.what()
						<< "\n\n\n";
		}
	}

	{
		std::cout	<< GREEN
					<< "* * * Test: Top-level bureaucrat * * *\n"
					<< RESET;

		Bureaucrat	boss("Boss", 1);
		Form		topSecret("TopSecret", 1, 1);

		std::cout	<< boss
					<< std::endl;
		boss.signForm(topSecret);
		std::cout	<< topSecret
					<< std::endl;
	}

	return (0);
}