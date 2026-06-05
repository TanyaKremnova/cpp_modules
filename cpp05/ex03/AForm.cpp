#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("DefAForm"),
	_signed(false),
	_gradeForSign(1),
	_gradeForExecute(150)
{
}
AForm::AForm(const std::string &name, int gradeForSign, int gradeForExecute)
	: _name(name),
	_signed(false),
	_gradeForSign(gradeForSign),
	_gradeForExecute(gradeForExecute)
{
	if (gradeForSign < 1 || gradeForExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeForSign > 150 || gradeForExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	_signed(other._signed),
	_gradeForSign(other._gradeForSign),
	_gradeForExecute(other._gradeForExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeForSign() const
{
	return (_gradeForSign);
}

int	AForm::getGradeForExecute() const
{
	return (_gradeForExecute);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed\n");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out	<< "[Form]" << std::endl
		<< MAGENTA
		<< "   Name            : "
		<< form.getName() << std::endl
		<< RESET
		<< "   Signed          : "
		<< (form.getSigned() ? "yes" : "no") << std::endl
		<< "   Grade to sign   : "
		<< form.getGradeForSign() << std::endl
		<< "   Grade to execute: "
		<< form.getGradeForExecute() << std::endl;
	return (out);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeForSign)
	{
		throw AForm::GradeTooLowException();
	}

	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > this->getGradeForExecute())
	{
		throw AForm::GradeTooLowException();
	}

	this->executeAction(); // different for each form
}