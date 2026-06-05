#include "ScalarConverter.hpp"

bool	isPseudoLiteral(const std::string &s)
{
	return (s == "nan" || s == "nanf"
		|| s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff");
}

bool	isCharLiteral(const std::string &s)
{
	return (s.length() == 1
			&& std::isprint(s[0])
			&& !std::isdigit(s[0])
	);
}

// bool	isCharLiteral(const std::string &s)
// {
// 	return (s.length() == 3
// 			&& s[0] == '\''
// 			&& s[2] == '\''
// 			&& std::isprint(static_cast<unsigned char>(s[1]))
// 	);
// }

bool	isIntLiteral(const std::string &s)
{
	size_t	i = 0;

	if (s.empty())
		return (false);

	if (s[i] == '+' || s[i] == '-')
		i++;

	if (i == s.length())
		return (false);

	for (; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool	isFloatLiteral(const std::string &s)
{
	size_t	i = 0;
	bool	dotFound = false;
	bool	digitFound = false;

	if (s.length() < 4 || s.back() != 'f')
		return false;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (; i < s.length() - 1; i++)
	{
		if (std::isdigit(s[i]))
			digitFound = true;
		else if (s[i] == '.' && !dotFound)
			dotFound = true;
		else
			return false;
	}
	return (dotFound && digitFound);
}

bool	isDoubleLiteral(const std::string &s)
{
	size_t	i = 0;
	bool	dotFound = false;
	bool	digitFound = false;

	if (s.empty() || s.back() == 'f')
		return (false);

	if (s[i] == '+' || s[i] == '-')
		i++;
	
	if (i >= s.length())
		return (false);

	for (; i < s.length(); i++)
	{
		if (std::isdigit(s[i]))
			digitFound = true;
		else if (s[i] == '.' && !dotFound)
			dotFound = true;
		else
			return (false);
	}
	return (dotFound && digitFound);
}