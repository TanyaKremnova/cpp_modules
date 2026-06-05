#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[7;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class Intern
{
private:
	static AForm	*createShrubbery(const std::string &target);
	static AForm	*createRobotomy(const std::string &target);
	static AForm	*createPresidential(const std::string &target);

public:
	Intern() = default;
	Intern(const Intern &other) = delete; // because no data members
	Intern &operator=(const Intern &other) = delete; // because no data members
	~Intern() = default;

	AForm	*makeForm(const std::string &formName, const std::string &target);
};

#endif