#include <string>
#include <iostream>

#  define RED "\033[3;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str; // Pointer: stores address of str
	std::string	&stringREF = str; // Reference: alias to str


	std::cout	<< YELLOW
				<< "The memory address of the string variable is "
				<< &str
				<< std::endl
				<< RESET;

	std::cout	<< CYAN
				<< "The memory address held by stringPTR is "
				<< stringPTR
				<< std::endl
				<< RESET;

	std::cout	<< MAGENTA
				<< "The memory address held by stringREF is "
				<< &stringREF
				<< std::endl
				<< RESET;

	std::cout	<< std::endl;

	std::cout	<< YELLOW
				<< "The value of the string variable is "
				<< str
				<< std::endl
				<< RESET;

	std::cout	<< CYAN
				<< "The value pointed to by stringPTR is "
				<< *stringPTR // dereference pointer
				<< std::endl
				<< RESET;

	std::cout	<< MAGENTA
				<< "The value pointed to by stringREF is "
				<< stringREF // reference behaves like the variable
				<< std::endl
				<< RESET;

	return (EXIT_SUCCESS);
}