#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	// using iterator = ...; ---> public iterator alias
	using iterator = typename std::stack<T>::container_type::iterator;

	// std::stack<T>
	// 		-> has container_type
	// 				-> has iterator


	MutantStack() = default;

	MutantStack(const MutantStack &other) = default;
	MutantStack &operator=(const MutantStack &other) = default;

	~MutantStack() = default;

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif

// std::stack is a container adaptor:
// Internally it stores elements in another container (by default std::deque):
//
// stack
//  └── underlying container (deque by default)
//
//
// !!! The stack intentionally hides iterators because stack semantics only allow:
// 
// push()
// pop()
// top()
//
//
// !!! Inside std::stack exists a protected member:
// 
// container_type c;
// Because it is protected, a derived class can access it!

// MutantStack
//     ↓
// inherits std::stack
//     ↓
// std::stack wraps a container (deque by default)
//     ↓
// expose that container's iterators



// STL adaptors (std::stack, std::queue, std::priority_queue)
//         ↓
// wrap real containers
//         ↓
// real containers already have iterators
//         ↓
// you can expose them if needed


