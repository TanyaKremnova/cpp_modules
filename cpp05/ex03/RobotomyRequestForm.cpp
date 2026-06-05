#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
	_target("DefTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other),
	_target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout	<< GREEN
				<< "Makes some drilling noises\n"
				<< "DRRrrrrRRRRRrrrrrRRRrrrRrrrRRRRr\n"
				<< RESET
				<< CYAN
				<< "  ______________________\n"
				<< ".'   __                 `.\n"
				<< "|  .'__`.    = = = =     |_.-----._\n"
				<< "|  `.__.'    = = = =     | |     | \\ _______________\n"
				<< "|`.                      | |     |  |  ````````````,)\n"
				<< "|  `.                    |_|     |_/~~~~~~~~~~~~~~~'\n"
				<< "|    `-;___              | `-----'\n"
				<< "|        /\\``---..._____.'\n"
				<< "|       |  \\\n"
				<< "|       |   )\n"
				<< "|       |  /\n"
				<< "|       | /\n"
				<< "|       `(\n"
				<< "|         `.\n"
				<< "|           )\n"
				<< "`----------'\n"
				<< RESET;

	if (std::rand() % 2)
	{
		std::cout	<< GREEN
					<< _target
					<< " has been robotomized successfully\n"
					<< RESET;
	}
	else
	{
		std::cout	<< RED
					<< "Robotomy failed on "
					<< _target
					<< std::endl
					<< RESET;
	}
}