#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeForSign;
	const int			_gradeForExecute;

public:
	Form();
	Form(const std::string &name, int gradeForSign, int gradeForExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/* Getters */
	const std::string	&getName() const;
	bool				getSigned() const;
	int					getGradeForSign() const;
	int					getGradeForExecute() const;

	/* Exceptions */
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	/* Member function */
	void	beSigned(const Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif