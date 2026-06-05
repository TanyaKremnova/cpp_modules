#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137),
	_target("DefTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other),
	_target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file)
		return ;

	file	<< "               ,@@@@@@@,\n"
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			<< "       |o|        | |         | |\n"
			<< "       |.|        | |         | |\n"
			<< "     \\/   \\//_/__/   \\_//___\\/   \\_//__/_\n";
}