#include "PmergeMe.hpp"

static std::deque<int>						baseCase(std::deque<std::pair<int,int>> const &pairs,
											std::optional<int> leftover);

static std::deque<std::pair<int,int>>		buildWinnerPairs(std::deque<std::pair<int,int>> const &pairs,
											std::optional<int> &leftoverWinner);

static void									insertFirstLoser(std::deque<int> &mainChain,
											std::deque<std::pair<int,int>> const &pairs);

static std::deque<std::pair<int,int>>		collectPendingLosers(std::deque<std::pair<int,int>> const &pairs,
											int smallestWinner);

static void									insertPending(std::deque<int> &mainChain,
											std::deque<std::pair<int,int>> const &pending);

static void									binaryInsert(std::deque<int> &chain, int bi, std::deque<int>::iterator posA);

static std::deque<int>						jacobsthalOrder(int pendingCount);


std::deque<int>	PmergeMe::fordJohnsonDeque(
					std::deque<std::pair<int,int>> pairs,
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
	std::deque<std::pair<int,int>>		winnerPairs = buildWinnerPairs(pairs, leftoverWinner);

	std::deque<int>		mainChain = fordJohnsonDeque(winnerPairs, leftoverWinner);
	int					smallestWinner = mainChain[0];

	insertFirstLoser(mainChain, pairs);

	std::deque<std::pair<int,int>>		pending = collectPendingLosers(pairs, smallestWinner);

	insertPending(mainChain, pending);

	if (leftover.has_value())
	{
		auto	pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover.value());

		mainChain.insert(pos, leftover.value());
	}

	return (mainChain);
}

std::deque<int>	baseCase(std::deque<std::pair<int,int>> const &pairs,
							std::optional<int> leftover)
{
	std::deque<int>	result;

	result = {pairs[0].second, pairs[0].first};

	if (leftover.has_value())
	{
		auto	pos = std::lower_bound(result.begin(), result.end(), *leftover);
		result.insert(pos, *leftover);
	}
	return (result);
}

std::deque<std::pair<int,int>>	buildWinnerPairs(std::deque<std::pair<int,int>> const &pairs,
												std::optional<int> &leftoverWinner)
{
	std::deque<int>	winners;

	for (const auto &p : pairs)
		winners.push_back(p.first);

	if (winners.size() % 2 != 0)
	{
		leftoverWinner = winners.back();
		winners.pop_back();
	}

	std::deque<std::pair<int,int>>	winnerPairs;

	for (size_t i = 0; i < winners.size(); i += 2)
	{
		int	a = winners[i];
		int	b = winners[i + 1];

		if (a > b)
			winnerPairs.push_back({a, b});
		else
			winnerPairs.push_back({b, a});
	}

	return (winnerPairs);
}

void	insertFirstLoser(std::deque<int> &mainChain,
						std::deque<std::pair<int,int>> const &pairs)
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

std::deque<std::pair<int,int>>	collectPendingLosers(std::deque<std::pair<int,int>> const &pairs,
													int smallestWinner)
{
	std::deque<std::pair<int,int>>	pending;
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

void	insertPending(std::deque<int> &mainChain,
					std::deque<std::pair<int,int>> const &pending)
{
	std::deque<int>		order = jacobsthalOrder(pending.size());
	std::deque<bool>	used(pending.size(), false);

	for (int index : order)
	{
		int	i = index - 1;

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

void	binaryInsert(std::deque<int> &chain, int bi, std::deque<int>::iterator posA)
{
	auto	posInsert = std::lower_bound(chain.begin(), posA, bi);

	chain.insert(posInsert, bi);
}

std::deque<int>	jacobsthalOrder(int pendingCount)
{
	std::deque<int>	order;
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

		int	tNext = 2 * tPrev + tCurr;

		tPrev = tCurr;
		tCurr = tNext;
	}
	return (order);
}