#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	p;

		p.parseInput(argc, argv);
		p.sortVector();
		p.sortDeque();
		p.printResults();
	}
	catch(std::exception &e)
	{
		std::cerr	<< "Error\n";
		return (1);
	}

	return (0);
}

// ./PmergeMe 5
// ./PmergeMe 2 1
// ./PmergeMe 3 1 2
// ./PmergeMe 3 5 9 7 4
// ./PmergeMe 8 3 7 2 6 1 5 4
// ./PmergeMe 9 3 8 1 7
// ./PmergeMe 10 4 9 2 8 1 7
// ./PmergeMe 5 3 5 2 5 1
// ./PmergeMe 9 8 7 6 5 4 3 2 1
// ./PmergeMe 12 3 10 5 8 1 7 6 4 9 2 11
// ./PmergeMe 1 100 2 99 3 98 4 97 5 96
// ./PmergeMe 17 3 15 8 1 14 6 9 2 13 7 10 4 12 5 11 16

// ./PmergeMe 1 1 1 1
// ./PmergeMe 1 1 1 1 1 1 1 1 1 1
// ./PmergeMe 1 2 1 2 1 2
// ./PmergeMe 1 2 1 2 1 2 2 2 2 1 1 2 2 1 2

////////////////
// for i in {1..100}; do
//     shuf -i 1-100 -n 20 | tr '\n' ' ' | xargs ./PmergeMe
// done
////////////////

////////////////
// shuf -i 1-1000 -n 100 | tr '\n' ' ' | xargs ./PmergeMe
////////////////

// n  | ≤ F(n)
// ---|-----
// 1  | 0
// 2  | 1
// 3  | 3
// 4  | 5
// 5  | 7
// 6  | 10
// 7  | 13
// 8  | 16
// 9  | 19
// 10 | 22
// 11 | 26
// 12 | 29
// 13 | 34
// 14 | 38
// 15 | 42
// 16 | 46
// 17 | 50
// 18 | 53
// 19 | 57
// 20 | 62
// 21 | 66

////////////////
// stress test
// 21 elements should be ≤ 66 comparisons
// ./PmergeMe `seq 1 21 | shuf | tr '\n' ' '`
////////////////