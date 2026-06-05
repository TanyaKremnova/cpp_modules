#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *arr, const int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	iter(const T *arr, const int len, void (*f)(const T&))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

// void	iter(int* arr, int len, void (*f)(int&));
// void	iter(const int* arr, int len, void (*f)(const int&));

// int a[] = {1, 2, 3};
// iter(a, 3, modify);    // picks non-const overload

// const int b[] = {4, 5, 6};
// iter(b, 3, print);     // picks const overload

#endif