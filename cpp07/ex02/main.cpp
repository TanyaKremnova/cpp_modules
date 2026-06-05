#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int	main(int, char**)
{
	////////////// Dynamic allocation correctness //////////////
	////////////// If this fails → crash before output //////////////
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];
	srand(time(NULL));
	

	////////////// Writing through operator[] //////////////
	//  - operator[] returns T&
	//  - Memory is writable
	//  - No off-by-one errors
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	////////////// Deep copy (twice) //////////////
	// This checks:
	//  - copy constructor
	//  - copy of a copy
	//  - independent ownership
	//  - destructor safety when scope ends
	//  - If copy is shallow → double free → crash.
	// 
	// + Destructor correctness
	// At scope exit:
	// }
	// If:
	//  - destructor is missing
	//  - delete[] is wrong
	//  - memory is shared
	// → crash here.
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	////////////// Data integrity after copies //////////////
	// This ensures:
	//  - original array was not corrupted
	//  - copies didn’t modify shared memory
	//  - assignment/copy preserved values
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	////////////// Exception safety //////////////
	// After exceptions, this part still runs
	// If:
	//  - exception leaves object in broken state
	//  - partial deletion happened
	// → crash or UB here.
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout	<< "I added this message\n"; // <-----

	delete [] mirror; // No memory leaks
	return 0;
}