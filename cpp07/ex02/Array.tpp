#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <exception>

template <typename T>
Array<T>::Array() : _arr(nullptr), _n(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _n(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) : _arr(new T[other._n]), _n(other._n)
{
	for (unsigned int i = 0; i < _n; ++i)
	{
		_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);

	delete[] _arr;

	_n = other._n;
	_arr = new T[_n];

	for (unsigned int i = 0; i < _n; ++i)
	{
		_arr[i] = other._arr[i];
	}

	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _n)
		throw std::exception();
	return (_arr[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _n)
		throw std::exception();
	return (_arr[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_n);
}

#endif