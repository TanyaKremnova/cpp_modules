#include "ScalarConverter.hpp"

// NaN or ±inf → impossible
// Outside [0,127] → impossible
// Non-printable → Non displayable
// Else → 'c'
void	printChar(CharStatus status, char c)
{
	std::cout	<< "char: ";
	if (status == CHAR_IMPOSSIBLE)
		std::cout << "impossible\n";
	else if (status == CHAR_NON_DISPLAYABLE)
		std::cout << "Non displayable\n";
	else
		std::cout	<< "'" << c << "'\n";
}

// NaN or ±inf → impossible
// If overflow → impossible
// Else → print integer
void	printInt(bool ok, int value)
{
	std::cout	<< "int: ";

	if (!ok)
		std::cout	<< "impossible\n";
	else
		std::cout	<< value
					<< "\n";
}

// Always possible (except formatting)
// 42.0f
// nan → nanf
// ±inf → ±inff
void	printFloat(double value)
{
	std::cout	<< "float: ";

	if (std::isnan(value))
	{
		std::cout	<< "nanf\n";
		return ;
	}

	if (std::isinf(value))
	{
		std::cout	<< (value < 0 ? "-inff\n" : "+inff\n");
		return ;
	}

	float	f = static_cast<float>(value);

	std::cout << f;

	if (std::floor(f) == f)
		std::cout	<< ".0";

	std::cout	<<"f\n";
}

// Always possible
// 42.0
// nan → nan
// ±inf → ±inf
void	printDouble(double value)
{
	std::cout	<< "double: ";

	if (std::isnan(value))
	{
		std::cout	<< "nan\n";
		return ;
	}

	if (std::isinf(value))
	{
		std::cout	<< (value < 0 ? "-inf\n" : "+inf\n");
		return ;
	}

	std::cout << value;

	if (std::floor(value) == value)
		std::cout	<< ".0";

	std::cout	<<"\n";
}