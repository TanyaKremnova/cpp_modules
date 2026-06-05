#include "visualization.hpp"
#include "Colors.hpp"

////////////// Visualization/debug helper for Ford–Johnson //////////////

void	printChain(const std::vector<int> &chain, const std::string &label)
{
	std::cout	<< label
				<< ": ";

	for (int v : chain)
		std::cout	<< v
					<< " ";

	std::cout	<< std::endl;
}

void	printPairs(const std::vector<std::pair<int,int>> &pairs,
					const std::string &label)
{
	std::cout	<< label
				<< ": ";

	for (const auto &p : pairs)
		std::cout	<< "("
					<< p.first
					<< ","
					<< p.second
					<< ") ";

	std::cout	<< std::endl;
}

void	printInsertion(int ai, int bi)
{
	std::cout	<< "Insert b = "
				<< bi
				<< " before a = "
				<< ai
				<< std::endl;
}
