#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	success_test();
void	execute_unsigned_form();
void	grade_too_low();

int	main()
{
	success_test();
	// execute_unsigned_form();
	// grade_too_low();
}

void	success_test()
{
	std::srand(std::time(NULL));
	std::cout << BLUE << "\n===== BASIC SUCCESS TEST =====\n" << RESET;
	try
	{
		Bureaucrat				boss("Boss", 1);

		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("Bender");
		PresidentialPardonForm	pardon("Arthur");

		boss.signForm(shrub);
		boss.executeForm(shrub);
		std::cout	<< "-----------------------------------"
					<< std::endl
					<< std::endl;

		boss.signForm(robot);
		boss.executeForm(robot);
		std::cout	<< "-----------------------------------"
					<< std::endl
					<< std::endl;

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	execute_unsigned_form()
{
	std::cout << BLUE << "\n===== EXECUTE UNSIGNED FORM =====\n" << RESET;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	shrub("garden");

		boss.executeForm(shrub); // not signed
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	grade_too_low()
{
	std::cout << BLUE << "\n===== GRADE TOO LOW TO EXECUTE =====\n" << RESET;
	try
	{
		Bureaucrat				intern("Intern", 150);
		ShrubberyCreationForm	shrub("park");

		intern.signForm(shrub);
		intern.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

// Rule
// rand() % 2 → gives 0 or 1
// One is success, one is failure

// ⚠️ Important
// Seed the random generator ONCE, usually in main():

// std::srand(std::time(NULL));