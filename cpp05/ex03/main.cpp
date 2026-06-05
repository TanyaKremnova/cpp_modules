#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		Intern	someRandomIntern;
		AForm*	rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		delete rrf;
	}

	// {
	// 	Intern	intern;

	// 	AForm	*f1 = intern.makeForm("robotomy request", "Bender");
	// 	AForm	*f2 = intern.makeForm("shrubbery creation", "Home");
	// 	AForm	*f3 = intern.makeForm("blabla form", "Nowhere");
	// 	AForm	*f4 = intern.makeForm("presidential pardon", "Thanos");

	// 	Bureaucrat	boss("Boss", 1);

	// 	boss.signForm(*f4);
	// 	boss.executeForm(*f4);

	// 	delete f1;
	// 	delete f2;
	// 	if (f3)
	// 		delete f3;
	// 	delete f4;
	// }
}