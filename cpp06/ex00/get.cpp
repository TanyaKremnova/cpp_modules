#include "ScalarConverter.hpp"

CharStatus	getCharFromDouble(double value, char &out)
{
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < 0
		|| value > 127)
	{
		return (CHAR_IMPOSSIBLE);
	}

	out = static_cast<char>(value);

	if (!std::isprint(static_cast<unsigned char>(out)))
	{
		return (CHAR_NON_DISPLAYABLE);
	}

	return (CHAR_OK);
}

bool	getIntFromDouble(double value, int &out)
{
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		return (false);
	}

	out = static_cast<int>(value);
	return (true);
}

float	getFloatFromDouble(double value)
{
	return (static_cast<float>(value));
}

double	getDoubleFromDouble(double value)
{
	return (value);
}