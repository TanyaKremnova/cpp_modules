#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	/* Orthodox Canonical Form */
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	/* Getters */
	const std::string	&getName() const;
	int					getGrade() const;

	/* Grade modification */
	void				incrementGrade();
	void				decrementGrade();

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif