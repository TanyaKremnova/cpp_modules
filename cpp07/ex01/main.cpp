#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#include "iter.hpp"
#include <iostream>
#include <string>

void	increment(int &x);
void	printInt(const int &x);
void	printStr(const std::string &s);

int	main()
{
	{
		int	arr[] = {1, 2, 3, 4};

		std::cout	<< CYAN
					<<"Original int array: "
					<< RESET;
		std::cout	<< YELLOW;
		iter(arr, 4, printInt);
		std::cout	<< std::endl
					<< RESET;

		iter(arr, 4, increment);

		std::cout	<< CYAN
					<<"After increment: "
					<< RESET;
		std::cout	<< YELLOW;
		iter(arr, 4, printInt);
		std::cout	<< std::endl
					<< std::endl
					<< RESET;
	}

	{
		const int	constArr[] = {10, 20, 30};
	
		std::cout	<< MAGENTA
					<<"Const int array: "
					<< RESET;
		std::cout	<< YELLOW;
		iter(constArr, 3, printInt);
		std::cout	<< std::endl
					<< std::endl
					<< RESET;
	}

	{
		std::string strings[] = {"hello", "world"};
	
		std::cout	<< BLUE
					<<"String array: "
					<< RESET;
		std::cout	<< YELLOW;
		iter(strings, 2, printStr);
		std::cout	<< std::endl
					<< std::endl
					<< RESET;
	}

	return (0);
}

void	increment(int &x)
{
	x++;
}

void	printInt(const int &x)
{
	std::cout	<< x
				<< " ";
}

void	printStr(const std::string &s)
{
	std::cout	<< s
				<< " ";
}