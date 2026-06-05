#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

void	Span::addNumber(int num)
{
	if (_data.size() >= _N)
		throw std::runtime_error ("Cannot add number: Span is full!");

	_data.push_back(num);
}

unsigned int	Span::shortestSpan() const // Time complexity: O(n log n)
{
	if (_data.size() < 2)
		throw std::runtime_error ("Container has fewer than 2 numbers. No span can be found");

	std::vector<int> copy = _data;
	int minSpan = std::numeric_limits<int>::max();

	std::sort(copy.begin(), copy.end());

	for (auto it = std::next(copy.begin()); it != copy.end(); ++it)
	{
		auto prev = std::prev(it);
		if (minSpan > *it - *prev)
			minSpan = *it - *prev;
	}

	return (static_cast<unsigned int>(minSpan));
}

unsigned int	Span::longestSpan() const // Time complexity: O(n)
{
	if (_data.size() < 2)
		throw std::runtime_error ("Container has fewer than 2 numbers. No span can be found");

	int	max = *_data.begin();
	int	min = *_data.begin();

	for(auto num : _data)
	{
		if (num < min)
			min = num;
		if (num > max)
			max = num;
	}

	return (static_cast<unsigned int>(max - min));
}

const	std::vector<int> &Span::getData() const
{
	return (_data);
}