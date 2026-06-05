#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits> // std::numeric_limits<int>::min()...
#include <cmath> // std::isnan, std::isinf, std::isprint
#include <cstdlib> // std::strtol, std::strtof, std::strtod
#include <cerrno> // errno, ERANGE

class ScalarConverter
{
private:
	ScalarConverter() = delete;

	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter &operator=(const ScalarConverter &other) = delete;

	ScalarConverter(ScalarConverter &&other) noexcept = delete;
	ScalarConverter &operator=(ScalarConverter &&other) noexcept = delete;

	~ScalarConverter() = default;

public:
	static void	convert(const std::string &literal);
};

enum	LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

enum	CharStatus
{
	CHAR_OK,
	CHAR_NON_DISPLAYABLE,
	CHAR_IMPOSSIBLE
};

bool	isPseudoLiteral(const std::string &s);
bool	isCharLiteral(const std::string &s);
bool	isIntLiteral(const std::string &s);
bool	isFloatLiteral(const std::string &s);
bool	isDoubleLiteral(const std::string &s);

double	parsePseudo(const std::string &s);
double	parseChar(const std::string &s);
double	parseInt(const std::string &s);
double	parseFloat(const std::string &s);
double	parseDouble(const std::string &s);

CharStatus	getCharFromDouble(double value, char &out);
bool		getIntFromDouble(double value, int &out);
float		getFloatFromDouble(double value);
double		getDoubleFromDouble(double value);

void	printChar(CharStatus status, char c);
void	printInt(bool ok, int value);
void	printFloat(double value);
void	printDouble(double value);

#endif