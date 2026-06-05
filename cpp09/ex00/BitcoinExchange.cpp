#include "BitcoinExchange.hpp"

static void	trim(std::string &s);

void	BitcoinExchange::loadDatabase(const std::string& file)
{
	std::ifstream	ifs(file);
	std::string		line;

	if (!ifs)
		throw std::runtime_error("Error: could not open file.\n");

	if (!getline(ifs, line))
		throw std::runtime_error("Error: file empty or invalid.\n");


	while (getline(ifs, line))
	{
		if (line.empty())
			continue;

		size_t	pos = line.find(',');

		if (pos == std::string::npos)
			throw std::runtime_error("Error: invalid database format.\n");

		std::string	date = line.substr(0, pos);
		std::string	rateStr = line.substr(pos + 1);

		std::stringstream ss(rateStr);
		double rateDbl;

		if (!(ss >> rateDbl))
			throw std::runtime_error("Error: conversion fails.\n");

		_dataBase[date] = rateDbl;
	}

	if (_dataBase.empty())
		throw std::runtime_error("Error: empty file.\n");
}

void	BitcoinExchange::processInput(const std::string &file)
{
	std::ifstream	ifs(file);
	std::string		line;

	if (!ifs)
		throw std::runtime_error("Error: could not open file.\n");

	if (!std::getline(ifs, line))
		throw std::runtime_error("Error: file empty or invalid.\n");


	while (std::getline(ifs, line))
	{
		if (line.empty())
			continue;

		size_t	pos = line.find('|');

		if (pos == std::string::npos)
		{
			printBadInput(line);
			continue;
		}

		std::string	date = line.substr(0, pos);
		std::string	valueStr = line.substr(pos + 1);

		trim(date);
		trim(valueStr);

		if (!isValidDate(date))
		{
			printBadInput(line);
			continue;
		}

		double	value;
		if (!parseValue(valueStr, line, value))
			continue;

		processRate(date, value);
	}
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			return (false);

	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int	year, month, day;
	try
	{
		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 2));
		day = stoi(date.substr(8, 2));
	}
	catch(const std::exception& e)
	{
		return (false);
	}

	std::tm	tm_date = {};
	tm_date.tm_year = year - 1900; // tm_year = years since 1900
	tm_date.tm_mon = month - 1; // tm_mon = 0-11
	tm_date.tm_mday = day;

	// std::mktime() normalizes the tm structure:
	// If the date was invalid (like 02-31), tm_mday will "roll over" into the next month
	std::time_t	t = std::mktime(&tm_date);
	if (t == -1)
		return (false);

	// After mktime(), compare tm_date with the original input:
	// 	 - If it changed → invalid date
	// 	 - If it stayed the same → valid date
	return (tm_date.tm_year == year - 1900
			&& tm_date.tm_mon == month - 1
			&& tm_date.tm_mday == day);
}

bool	BitcoinExchange::parseValue(const std::string &str,
									const std::string &line,
									double &value) const
{
	size_t	idx = 0;

	try
	{
		value = std::stod(str, &idx);
	}
	catch(const std::exception& e)
	{
		printBadInput(line);
		return (false);
	}

	if (idx != str.size())
	{
		printBadInput(line);
		return (false);
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return (false);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return (false);
	}

	return (true);
}

void	BitcoinExchange::processRate(const std::string &date, double value) const
{
	if (_dataBase.empty())
	{
		std::cout << "Error: database empty.\n";
		return ;
	}

	auto	it = _dataBase.lower_bound(date);

	if (it == _dataBase.begin() && it->first > date)
	{
		std::cout	<< "Error: no earlier date.\n";
		return ;
	}

	if (it == _dataBase.end() || it->first != date)
		--it;

	double	result = value * it->second;

	std::cout	<< date
				<< " => "
				<< value
				<< " = "
				<< result
				<< std::endl;
}

void	trim(std::string &s)
{
	size_t	start = 0;

	while (start < s.size()
		&& std::isspace(static_cast<unsigned char>(s[start])))
	{
		++start;
	}

	size_t	end = s.size();

	while (end > start
		&& std::isspace(static_cast<unsigned char>(s[end - 1])))
	{
		--end;
	}

	s = s.substr(start, end - start);
}

void	BitcoinExchange::printBadInput(const std::string &line) const
{
	std::cout	<< "Error: bad input => "
				<< line
				<< std::endl;
}