#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

#  define RED_BG "\033[7;31m"
#  define GREEN_BG "\033[7;32m"
#  define YELLOW_BG "\033[7;33m"
#  define BLUE_BG "\033[7;34m"
#  define MAGENTA_BG "\033[7;35m"
#  define CYAN_BG "\033[7;36m"

#  define RESET "\033[0m"

int main()
{
	std::cout	<< GREEN_BG
				<< "* * * * * First occurrence check * * * * *\n"
				<< RESET;

	std::vector<int> vec = {0,1,5,3,5,6};

	auto it = easyfind(vec, 5);
	std::cout	<< "First occurrence at index: "
				<< std::distance(vec.begin(), it)
				<< std::endl;


	////////////////////////////////////////////////////////////////////


	std::cout	<< GREEN_BG
				<< "\n* * * * * Multi-container test * * * * *\n"
				<< RESET;

	std::vector<int>	v = {0,1,2,3,4,5};
	std::list<int>		l = {0,1,2,3,4,5};
	std::deque<int>		d = {0,1,2,3,4,5};

	try
	{
		auto itVector = easyfind(v, 1);
		auto itList = easyfind(l, 2);
		auto itDeque = easyfind(d, 3);

		std::cout	<< "Vector: "
					<< *itVector
					<< " at index: "
					<< std::distance(v.begin(), itVector)
					<< std::endl;

		std::cout	<< "List: "
					<< *itList
					<< " at index: "
					<< std::distance(l.begin(), itList)
					<< std::endl;

		std::cout	<< "Deque: "
					<< *itDeque
					<< " at index: "
					<< std::distance(d.begin(), itDeque)
					<< std::endl;


	////////////////////////////////////////////////////////////////////


	std::cout	<< MAGENTA_BG
				<< "\n* * * * * Modification test * * * * *\n"
				<< RESET;

		*itVector = 99; //iterators provide direct access to container elements, not copies

		std::cout	<< "Modified vector value: "
					<< v[1]
					<< std::endl;
		for (int x : v)
			std::cout	<< x << " ";
		std::cout	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	////////////////////////////////////////////////////////////////////


	std::cout	<< RED_BG
				<< "\n* * * * * Not found test * * * * *\n"
				<< RESET;

	try
	{
		easyfind(v, 10);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	////////////////////////////////////////////////////////////////////


	std::cout	<< BLUE_BG
				<< "\n* * * * * Const container test * * * * *\n"
				<< RESET;

	const std::vector<int> constV = {0,1,2,3};

	try
	{
		auto constIt = easyfind(constV, 2);
		std::cout	<< "Const vector: "
					<< *constIt
					<< " at index: "
					<< std::distance(constV.begin(), constIt)
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}

// Wrong:
// for (size_t i = 0; i < container.size(); ++i)
// the code works for vector, but fails for list, because list has no indexing
