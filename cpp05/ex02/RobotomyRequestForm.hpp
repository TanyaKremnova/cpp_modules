#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[7;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void	executeAction() const;
};

#endif