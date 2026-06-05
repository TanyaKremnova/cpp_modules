#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <algorithm>
#include <stdexcept>

template <typename T>
auto easyfind(T &container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("I couldn't find it :`(");

	return it;
}

#endif

// C++ STL is built on three layers:
//
// Containers   -> hold data		// Containers are generic classes that can store any type
// Iterators    -> access data		// Iterator is an object behaving like a pointer
// Algorithms   -> process data		// STL algorithms work using iterators
//
// Algorithms do not know container type.
// Algorithms never work directly with containers.
// They work with iterator ranges, not containers.



// it = std::find(container.begin(), container.end(), value)
//               |
//               |
//               V
// for (it = begin; it != end; ++it)
// {
//     if (*it == value)
//         return (it);
// }
// return (end);
