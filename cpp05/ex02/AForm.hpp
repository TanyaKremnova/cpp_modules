#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeForSign;
	const int			_gradeForExecute;

public:
	AForm();
	AForm(const std::string &name, int gradeForSign, int gradeForExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	/* Member function */
	void			beSigned(const Bureaucrat &bureaucrat);
	void			execute(Bureaucrat const & executor) const;
	virtual void	executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif