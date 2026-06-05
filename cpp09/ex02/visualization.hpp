#ifndef VISUALIZATION_HPP
# define VISUALIZATION_HPP

#include <vector>
#include <string>
#include <iostream>

void	printChain(const std::vector<int> &chain, const std::string &label);
void	printPairs(const std::vector<std::pair<int,int>> &pairs,
					const std::string &label);
void	printInsertion(int ai, int bi);

#endif