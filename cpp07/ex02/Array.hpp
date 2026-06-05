#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef> // size_t
#include <exception> // std::exception

template <typename T>
class Array
{
private:
	T				*_arr;
	unsigned int	_n;

public:
	Array();
	Array(unsigned int n);

	Array(const Array &other);
	Array &operator=(const Array &other);

	~Array();

	// Element access
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	// Size
	unsigned int	size() const;
};

#include "Array.tpp"

#endif

// class Array is closer to -> std::vector<T> with fixed size + checked []

// RAII - Resource Acquisition Is Initialization
//		  (The resource lifetime is related to the object lifetime, preventing leaks)

// 	- std::vector: owning, resizable, safe dynamic array
// 	- Vector copying: expensive because deep copy is required
// 	- operator[]: fast, unchecked access
// 	- at(): safe, checked access that throws