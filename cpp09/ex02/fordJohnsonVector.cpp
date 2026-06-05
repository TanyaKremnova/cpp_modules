#include "PmergeMe.hpp"

static std::vector<int>						baseCase(std::vector<std::pair<int,int>> const &pairs,
											std::optional<int> leftover);

static std::vector<std::pair<int,int>>		buildWinnerPairs(std::vector<std::pair<int,int>> const &pairs,
											std::optional<int> &leftoverWinner);

static void									insertFirstLoser(std::vector<int> &mainChain,
											std::vector<std::pair<int,int>> const &pairs);

static std::vector<std::pair<int,int>>		collectPendingLosers(std::vector<std::pair<int,int>> const &pairs,
											int smallestWinner);

static void									insertPending(std::vector<int> &mainChain,
											std::vector<std::pair<int,int>> const &pending);

static void									binaryInsert(std::vector<int> &chain, int bi, std::vector<int>::iterator posA);

static std::vector<int>						jacobsthalOrder(int pendingCount);
static bool									compare(int a, int b);



// mainChain = fordJohnsonVector(...)
// insertFirstLoser(mainChain, pairs)
// pending = collectPendingLosers(...)
// insertPending(mainChain, pending)
// if (leftover)
// 		mainChain.insert(pos, leftover.value())
std::vector<int>	PmergeMe::fordJohnsonVector(
					std::vector<std::pair<int,int>> pairs,
					std::optional<int> leftover)
{
	if (pairs.empty())
	{
		if (leftover.has_value())
			return { leftover.value() };
		return {};
	}

	if (pairs.size() == 1)
		return baseCase(pairs, leftover);

	std::optional<int>					leftoverWinner;
	std::vector<std::pair<int,int>>		winnerPairs = buildWinnerPairs(pairs, leftoverWinner);

	{	////////////////// visualization.hpp
		if (DEBUG2)
		{
			printPairs(pairs, "Pairs");
			printPairs(winnerPairs, "WinnerPairs");
			std::cout	<< std::endl;
		}
	}

	std::vector<int>	mainChain = fordJohnsonVector(winnerPairs, leftoverWinner);
	int					smallestWinner = mainChain[0];

	{	////////////////// visualization.hpp
		if (DEBUG2)
			printChain(mainChain, "Chain after recursion (winners sorted)");
	}

	insertFirstLoser(mainChain, pairs);

	{	////////////////// visualization.hpp
		if (DEBUG2)
			printChain(mainChain, "After inserting b1");
	}

	std::vector<std::pair<int,int>>		pending = collectPendingLosers(pairs, smallestWinner);

	{	////////////////// visualization.hpp
		if (DEBUG2)
		{
			printPairs(pending, "Pending pairs");
			std::cout	<< std::endl;
		}
	}

	insertPending(mainChain, pending);

	{	////////////////// visualization.hpp
		if (DEBUG2)
		{
			printChain(mainChain, "After pending insertion");
			std::cout	<< std::endl;
		}
	}

	if (leftover.has_value())
	{
		auto	pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover.value());

		mainChain.insert(pos, leftover.value());
	}

	return (mainChain);
}

std::vector<int>	baseCase(std::vector<std::pair<int,int>> const &pairs,
							std::optional<int> leftover)
{
	std::vector<int>	result;

	result = {pairs[0].second, pairs[0].first}; // {b1, a1} <smaller, bigger> -> (1, 2)

	if (leftover.has_value())
	{
		auto	pos = std::lower_bound(result.begin(), result.end(), *leftover);
		result.insert(pos, *leftover);
	}
	return (result);
}

std::vector<std::pair<int,int>>	buildWinnerPairs(std::vector<std::pair<int,int>> const &pairs,
												std::optional<int> &leftoverWinner)
{
	std::vector<int>	winners;

	for (const auto &p : pairs)
		winners.push_back(p.first);

	if (winners.size() % 2 != 0)
	{
		leftoverWinner = winners.back();
		winners.pop_back();
	}

	std::vector<std::pair<int,int>>	winnerPairs;

	for (size_t i = 0; i < winners.size(); i += 2)
	{
		int	a = winners[i];
		int	b = winners[i + 1];

		comparisons++;

		if (a > b)
			winnerPairs.push_back({a, b});
		else
			winnerPairs.push_back({b, a});
	}

	return (winnerPairs);
}

void	insertFirstLoser(std::vector<int> &mainChain,
						std::vector<std::pair<int,int>> const &pairs)
{
	if (mainChain.empty())
		return ;

	int	smallestWinner = mainChain[0];

	for (auto const &p : pairs)
	{
		if (p.first == smallestWinner)
		{
			mainChain.insert(mainChain.begin(), p.second);
			break;
		}
	}
}

std::vector<std::pair<int,int>>	collectPendingLosers(std::vector<std::pair<int,int>> const &pairs,
													int smallestWinner)
{
	std::vector<std::pair<int,int>>	pending;
	bool							skipped = false;

	for (auto const &p : pairs)
	{
		if (!skipped && p.first == smallestWinner)
		{
			skipped = true;
			continue;
		}
		pending.push_back(p);
	}

	return (pending);
}

void	insertPending(std::vector<int> &mainChain,
					std::vector<std::pair<int,int>> const &pending)
{
	std::vector<int>	order = jacobsthalOrder(pending.size()); // 1-based indices
	std::vector<bool>	used(pending.size(), false);

	for (int index : order)
	{
		int	i = index - 1; // convert to 0-based index

		if (i >= 0 && i < (int)pending.size())
		{
			int	ai = pending[i].first;
			int	bi = pending[i].second;

			auto	posA = std::find(mainChain.begin(), mainChain.end(), ai);

			binaryInsert(mainChain, bi, posA);
			used[i] = true;
		}
	}

	for (size_t i = 0; i < pending.size(); ++i)
	{
		if (!used[i])
		{
			int	ai = pending[i].first;
			int	bi = pending[i].second;

			auto	posA = std::find(mainChain.begin(), mainChain.end(), ai);
			binaryInsert(mainChain, bi, posA);
		}
	}
}

void	binaryInsert(std::vector<int> &chain, int bi, std::vector<int>::iterator posA)
{
	auto	posInsert = std::lower_bound(chain.begin(), posA, bi, compare);

	chain.insert(posInsert, bi);
}

std::vector<int>	jacobsthalOrder(int pendingCount)
{
	std::vector<int>	order;
	int					tPrev = 1;
	int					tCurr = 3;

	while (true)
	{
		int	start = std::min(tCurr, pendingCount);
		int	end = tPrev + 1;

		if (end > pendingCount)
			break;

		for (int i = start; i >= end; i--)
			order.push_back(i);

		int	tNext = 2 * tPrev + tCurr; // 1, 3, 5, 11, 21, 43, 85

		tPrev = tCurr;
		tCurr = tNext;
	}
	return (order);
}

bool	compare(int a, int b)
{
	comparisons++;
	return (a < b);
}

// {
	// Jacobsthal Sequence index order (1-based):
	// 1, 3, 5, 11, 21, 43, 85, 171, ...
	//
	// if size = 15 numbers
	// indexes:
	// 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 15, 14, 13, 12
// }