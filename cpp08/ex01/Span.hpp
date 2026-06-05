#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>

class Span
{
private:
	unsigned int		_N; // max allowed elements
	std::vector<int>	_data; // stored numbers

public:
	Span() = default;
	Span(unsigned int N);

	Span(const Span &other) = default;
	Span &operator=(const Span &other) = default;

	~Span() = default;

	void			addNumber(int num);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template<typename It>
	void	addRange(It begin, It end);

	const	std::vector<int> &getData() const;
};

#include "Span.tpp"

#endif

// Span
//  ├── N (fixed capacity)
//  ├── vector<int> storage
//  ├── addNumber() -> push_back
//  ├── addRange() -> insert(range)
//  ├── shortestSpan() -> sort copy + scan neighbors
//  └── longestSpan() -> max - min
