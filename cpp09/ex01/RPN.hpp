#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
private:
	std::stack<int> _stack;

	void	processToken(const std::string &token);
	void	applyOperator(char op);

public:
	RPN() = default;

	RPN(const RPN &other) = default;
	RPN &operator=(const RPN &other) = default;

	~RPN() = default;

	void	evaluate(const std::string &expression);
};

#endif

// Reverse Polish Notation ("3 + 4" becomes "3 4 +") requires:
// 	- process tokens left to right
// 	- push numbers
// 	- pop two values when operator appears
// 	- push result back
// 	- LIFO behavior
//
// std::stack
// 	- LIFO container adapter
// 	- push() and pop() are O(1)
// 	- prevents random access (safer abstraction)