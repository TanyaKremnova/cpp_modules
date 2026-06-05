#include "ScalarConverter.hpp"

double	parsePseudo(const std::string &s)
{
	if (s == "nan" || s == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	if (s == "+inf" || s == "+inff")
		return (std::numeric_limits<double>::infinity());
	if (s == "-inf" || s == "-inff")
		return (-std::numeric_limits<double>::infinity());
	return (0.0);
}

double	parseChar(const std::string &s)
{
	return (static_cast<double>(s[0]));
}

double	parseInt(const std::string &s)
{
	errno = 0;
	long	value = std::strtol(s.c_str(), NULL, 10);

	if (errno == ERANGE // ERANGE - Result out of range
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw(std::out_of_range("int overflow"));
	
	return (static_cast<double>(value));
}

double	parseFloat(const std::string &s)
{
	return (static_cast<double>(std::strtof(s.c_str(), NULL)));
}

double	parseDouble(const std::string &s)
{
	return (std::strtod(s.c_str(), NULL));
}