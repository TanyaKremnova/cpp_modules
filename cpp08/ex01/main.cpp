#include "Span.hpp"
#include <iostream>
#include <list>
#include <deque>

#  define RED_BG "\033[7;31m"
#  define GREEN_BG "\033[7;32m"
#  define YELLOW_BG "\033[7;33m"
#  define BLUE_BG "\033[7;34m"
#  define MAGENTA_BG "\033[7;35m"
#  define CYAN_BG "\033[7;36m"

#  define RESET "\033[0m"

// int	main()
// {
// 	Span	sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

int	main()
{
	{
		std::cout	<< GREEN_BG
					<< "* * * * * Duplicate values * * * * *\n"
					<< RESET;

		Span	sp(5);

		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(20);

		std::cout	<< "Shortest span: "
					<< sp.shortestSpan()
					<< std::endl;
		std::cout	<< "Longest span: "
					<< sp.longestSpan()
					<< std::endl
					<< std::endl;
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< GREEN_BG
					<< "* * * * * Negative and mixed numbers * * * * *\n"
					<< RESET;

		Span	sp(5);

		sp.addNumber(-10);
		sp.addNumber(5);
		sp.addNumber(100);

		std::cout	<< "Shortest span: "
					<< sp.shortestSpan()
					<< std::endl;
		std::cout	<< "Longest span: "
					<< sp.longestSpan()
					<< std::endl
					<< std::endl;
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< MAGENTA_BG
					<< "* * * * * Different containers * * * * *\n"
					<< RESET;
	
		Span				sp(20);
		std::vector<int>	v = {0,1,2,3,4};
		std::list<int>		l = {10,20,30,40,50};
		std::deque<int>		d = {100,200,300};
		int					arr[] = {1000,2000,3000};
		
		sp.addRange(v.begin(), v.end());
		sp.addRange(l.begin(), l.end());
		sp.addRange(d.begin(), d.end());
		sp.addRange(arr, arr + 3);

		for (auto num : sp.getData())
		{
			std::cout	<< num
						<< " ";
		}

		std::cout	<< "\nShortest span: "
					<< sp.shortestSpan()
					<< std::endl;
		std::cout	<< "Longest span: "
					<< sp.longestSpan()
					<< std::endl
					<< std::endl;
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< MAGENTA_BG
					<< "* * * * * Large insert * * * * *\n"
					<< RESET;
	
		Span				sp(10000);
		std::vector<int>	v(10000);

		for (int i = 0; i < 10000; i++)
			v[i] = i;
		
		sp.addRange(v.begin(), v.end());

		std::cout	<< "Shortest span: "
					<< sp.shortestSpan()
					<< std::endl;
		std::cout	<< "Longest span: "
					<< sp.longestSpan()
					<< std::endl
					<< std::endl;
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< RED_BG
					<< "* * * * * Full container * * * * *\n"
					<< RESET;
	
		Span	sp(2);
	
		sp.addNumber(1);
		sp.addNumber(2);

		try
		{
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
	}

	////////////////////////////////////////////////////////////////////


	{
		std::cout	<< RED_BG
					<< "* * * * * Not enough elements * * * * *\n"
					<< RESET;
	
		Span	sp(5);
	
		sp.addNumber(1);

		try
		{
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}

		try
		{
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< RED_BG
					<< "* * * * * Capacity overflow via addRange * * * * *\n"
					<< RESET;
	
		Span				sp(5);
		std::vector<int>	v(10, 1);

		try
		{
			sp.addRange(v.begin(), v.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
	}

	////////////////////////////////////////////////////////////////////

	{
		std::cout	<< MAGENTA_BG
					<< "* * * * * Stress test * * * * *\n"
					<< RESET;

		Span	sp(20000);

		for (int i = 0; i < 20000; ++i)
			sp.addNumber(rand() % 500);

		std::cout	<< "Shortest span: "
					<< sp.shortestSpan()
					<< std::endl;
		std::cout	<< "Longest span: "
					<< sp.longestSpan()
					<< std::endl
					<< std::endl;
	}

	return (0);
}


