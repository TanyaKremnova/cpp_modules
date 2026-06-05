#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <ctime>

class BitcoinExchange
{
private:
	std::map<std::string, double> _dataBase; // Key = date // Value = exchange_rate

	bool		isValidDate(const std::string&date) const;

	bool		parseValue(const std::string &str,
							const std::string &line,
							double& value) const;

	void		processRate(const std::string &date, double value) const;

	void		printBadInput(const std::string &line) const;

public:
	BitcoinExchange() = default;

	BitcoinExchange(const BitcoinExchange &other) = default;
	BitcoinExchange &operator=(const BitcoinExchange &other) = default;

	~BitcoinExchange() = default;

	void	loadDatabase(const std::string &file);
	void	processInput(const std::string &file);
};

#endif

// We need:
// 	- store date → price
// 	- automatic sorting by date
// 	- fast lookup
// 	- ability to find closest LOWER date

// std::map
// 	- ordered associative container (red-black tree)
// 	- elements automatically sorted by key
// 	- lookup O(log n)
// 	- supports lower_bound()
// 	- allows finding closest lower date easily