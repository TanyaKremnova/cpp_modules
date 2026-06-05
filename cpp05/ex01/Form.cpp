#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("DefForm"),
	_signed(false),
	_gradeForSign(1),
	_gradeForExecute(150)
{
}
Form::Form(const std::string &name, int gradeForSign, int gradeForExecute)
	: _name(name),
	_signed(false),
	_gradeForSign(gradeForSign),
	_gradeForExecute(gradeForExecute)
{
	if (gradeForSign < 1 || gradeForExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeForSign > 150 || gradeForExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	_signed(other._signed),
	_gradeForSign(other._gradeForSign),
	_gradeForExecute(other._gradeForExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeForSign() const
{
	return (_gradeForSign);
}

int	Form::getGradeForExecute() const
{
	return (_gradeForExecute);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
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

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeForSign)
	{
		throw Form::GradeTooLowException();
	}

	_signed = true;
}