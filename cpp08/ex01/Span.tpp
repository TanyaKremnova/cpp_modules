#ifndef SPAN_TPP
# define SPAN_TPP

template<typename It>
void	Span::addRange(It begin, It end)
{
	auto	diff = std::distance(begin, end);

	if (diff < 0)
		throw std::runtime_error("Invalid iterator range");

	size_t	numbs = static_cast<size_t>(diff);

	if (_data.size() + numbs > _N)
		throw std::runtime_error("Too many numbers to add");
	
	_data.insert(_data.end(), begin, end);
}

#endif