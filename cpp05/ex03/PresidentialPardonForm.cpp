#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5),
	_target("DefTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other),
	_target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout	<< YELLOW
			<< "   _____________________________\n"
			<< "  |                             |\n"
			<< "  |     PRESIDENTIAL PARDON     |\n"
			<< "  |_____________________________|\n"
			<< "          \\   ^__^\n"
			<< "           \\  (oo)\\_______\n"
			<< "              (__)\\       )\\\n"
			<< "                  ||----w |\n"
			<< "                  ||     ||\n"
			<< RESET
			<< std::endl;

	std::cout	<< CYAN
				<< _target
				<< " has been pardoned by Zaphod Beeblebrox\n"
				<< RESET;
}