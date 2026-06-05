#include "Intern.hpp"

// Intern::Intern()
// {
// }

// Intern::Intern(const Intern &other)
// {
// }

// Intern &Intern::operator=(const Intern &other)
// {
// 	return (*this);
// }

// Intern::~Intern()
// {
// }

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	// 1) Lookup table: form names
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// 2) Lookup table: creation functions
	static AForm *(*creators[3])(const std::string &) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout	<< GREEN
						<< "Intern creates "
						<< formName
						<< std::endl
						<< RESET;
			return (creators[i](target));
		}
	}
	std::cerr	<< RED
				<< "Intern cannot create form: "
				<< formName
				<< std::endl
				<< RESET;
	return (NULL);
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
