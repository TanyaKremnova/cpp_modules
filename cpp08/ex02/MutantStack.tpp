#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

// Pattern
// template<typename T>
// typename Class<T>::type Class<T>::function(...)

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin()); // this->c.begin() returns the iterator of the underlying container
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif