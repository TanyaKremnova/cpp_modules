#include "RPN.hpp"

void	RPN::evaluate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
		processToken(token);

	if (_stack.size() != 1)
		throw std::runtime_error("...");

	std::cout	<< _stack.top() << std::endl;
}

void	RPN::processToken(const std::string &token)
{
	if (token.size() != 1)
		throw std::runtime_error("...");

	char	c = token[0];

	if (std::isdigit(c))
	{
		_stack.push(c - '0');
	}
	else if (c == '+' || c == '*' || c == '-' || c == '/')
	{
		applyOperator(c);
	}
	else
		throw std::runtime_error("...");
}

void	RPN::applyOperator(char op)
{
	int	right;
	int	left;
	int	result;

	if (_stack.size() < 2)
		throw std::runtime_error("...");

	right = _stack.top();
	_stack.pop();
	left = _stack.top();
	_stack.pop();
	if (op == '+')
		result = left + right;
	else if (op == '*')
		result = left * right;
	else if (op == '-')
		result = left - right;
	else
	{
		if (right == 0)
			throw std::runtime_error("...");

		result = left / right;
	}

	_stack.push(result);
}
