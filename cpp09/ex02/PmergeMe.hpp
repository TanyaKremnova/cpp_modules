#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <optional>
#include <iostream>
#include <chrono>
#include <algorithm>

#include "visualization.hpp"
#include "Colors.hpp"

// inline constexpr -> modern C++ style (same as static const bool)
inline constexpr bool	DEBUG1 = true; // std::vector
inline constexpr bool	DEBUG2 = false; // Pairs visualization
inline constexpr bool	DEBUG3 = true; // Comparisons

extern size_t	comparisons; //extern a single variable shared across the whole program

class PmergeMe
{
private:
	std::vector<int>	_vector; // for insert in middle -> shifts memory
	std::deque<int>		_deque; // for insert in middle -> shifts blocks

	std::vector<int>	_originalV;
	std::deque<int>		_originalD;

	double	_vectorTime;
	double	_dequeTime;

	std::vector<int>	fordJohnsonVector(
						std::vector<std::pair<int,int>> pairs,
						std::optional<int> leftover);

	std::deque<int>		fordJohnsonDeque(
						std::deque<std::pair<int,int>> pairs,
						std::optional<int> leftover);

public:
	PmergeMe() = default;

	PmergeMe(const PmergeMe &other) = default;
	PmergeMe &operator=(const PmergeMe &other) = default;

	~PmergeMe() = default;

	void	parseInput(int argc, char **argv);
	void	sortVector();
	void	sortDeque();
	void	printResults();
};

#endif

// The Ford-Johnson algorithm tries to sort using as few comparisons
// as possible. O(n log n) closer to the theoretical lower bound
// on comparisons log2(n!)
//
// Slower in real-world CPU time than:
// 	- std::sort (introsort)
// 	- Merge sort
// 	- Quick sort
// Because minimizing comparisons ≠ minimizing time.


// Ford-Johnson requires:
// 	- frequent insertions
// 	- comparisons
// 	- binary-search-like behavior
// 	- indexed access is very helpful

// std::vector
// 	- random access O(1)
// 	- contiguous memory
// 	- best for binary insertion
// 	- fastest in most cases

// std::deque
// 	- random access O(1)
// 	- different memory layout (segmented blocks)
// 	- good comparison target
// 	- easy to implement same algorithm

// !std::list
// 	- no random access
// 	- binary insertion becomes iterator-based
// 	- much harder