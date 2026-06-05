#include "PmergeMe.hpp"

size_t	comparisons = 0;

void	PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("...");

	_vector.reserve(argc - 1);
	_originalV.reserve(argc - 1);

	for (int i = 1; i < argc; i++)
	{
		int			num;
		std::string	str(argv[i]);

		for (unsigned char c : str)
		{
			if (!std::isdigit(c))
				throw std::runtime_error("...");
		}

		try
		{
			num = std::stoi(str);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("...");
		}

		if (num < 0)
			throw std::runtime_error("...");

		_vector.push_back(num);
		_deque.push_back(num);
		_originalV.push_back(num);
		_originalD.push_back(num);
	}
}

void	PmergeMe::sortVector() //pair up raw integers
{
	comparisons = 0;

	std::vector<std::pair<int,int>>	pairs;
	std::optional<int>				leftover = std::nullopt;

	auto	start = std::chrono::high_resolution_clock::now();

	if (_vector.size() % 2 != 0)
		leftover = _vector.back();

	for (size_t i = 0; i + 1 < _vector.size(); i += 2) // pair creation
	{
		comparisons++;

		if (_vector[i] > _vector[i + 1])
			pairs.push_back({_vector[i], _vector[i + 1]}); // <bigger, smaller> or <first, second>
		else
			pairs.push_back({_vector[i + 1], _vector[i]});
	}

	_vector = fordJohnsonVector(pairs, leftover);

	auto	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro>	duration = end - start;
	_vectorTime = duration.count(); // stores microseconds as double
}

void	PmergeMe::sortDeque()
{
	std::deque<std::pair<int,int>>	pairs;
	std::optional<int>				leftover = std::nullopt;
	
	auto	start = std::chrono::high_resolution_clock::now();

	if (_deque.size() % 2 != 0)
		leftover = _deque.back();

	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		if (_deque[i] > _deque[i + 1])
			pairs.push_back({_deque[i], _deque[i + 1]});
		else
			pairs.push_back({_deque[i + 1], _deque[i]});
	}

	_deque = fordJohnsonDeque(pairs, leftover);

	auto	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro>	duration = end - start;
	_dequeTime = duration.count();
}

void	PmergeMe::printResults()
{
	{
		std::cout	<< "Before:	";
	
		for (const int i : _originalV)
		{
			std::cout	<< i
						<< " ";
		}
		std::cout	<< std::endl;
	}

	{
		std::cout	<< "After:	";
	
		for (const int i : _vector)
		{
			std::cout	<< i
						<< " ";
		}
		std::cout	<< std::endl;
	}

	{
		std::cout	<< "Time to process a range of "
					<< _originalV.size()
					<< " elements with std::vector : "
					<< _vectorTime
					<< " us"
					<< std::endl;

		if (DEBUG1)
		{
			std::cout	<< BLUE
						<< _vector.size()
						<< " elements in sorted std::vector\n"
						<< RESET;
		}
	}

	{
		std::cout	<< "Time to process a range of "
					<< _originalD.size()
					<< " elements with std::deque : "
					<< _dequeTime
					<< " us"
					<< std::endl;

		if (DEBUG1)
		{
			std::cout	<< BLUE
						<< _deque.size()
						<< " elements in sorted std::deque\n"
						<< RESET;
		}
	}

	if (DEBUG1)
	{
		std::vector<int>	check = _originalV;
		std::sort(check.begin(), check.end());

		std::cout	<< std::endl;

		if (check != _vector)
		{
			std::cout	<< RED
						<< "std::vector -> Mismatch detected\n"
						<< RESET;
		}
		else
		{
					std::cout	<< GREEN
								<< "std::vector -> OoooooooooooooOOOOOOooooooKkkk!\n"
								<< RESET;
		}
	}

	if (DEBUG1)
	{
		double			_sortTime;
		std::deque<int>	check = _originalD;

		auto	start = std::chrono::high_resolution_clock::now();

		std::sort(check.begin(), check.end());

		auto	end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro>	duration = end - start;
		_sortTime = duration.count();

		if (check != _deque)
		{
			std::cout	<< RED
						<< "std::deque -> Mismatch detected\n"
						<< RESET;
		}
		else
		{
			std::cout	<< GREEN
						<< "std::deque -> OoooooooooooooOOOOOOooooooKkkk!\n"
						<< RESET;
		}

		std::cout	<< MAGENTA
					<< "\nTime to process a range of "
					<< _originalD.size()
					<< " elements with std::sort : "
					<< _sortTime
					<< " us"
					<< std::endl
					<< RESET;
	}

	if (DEBUG3)
	{
		std::cout	<< GREEN_HI
					<< "\nComparisons: "
					<< comparisons
					<< std::endl
					<< RESET;
	}
}
