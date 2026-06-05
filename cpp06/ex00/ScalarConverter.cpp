#include "ScalarConverter.hpp"

LiteralType	detectType(const std::string &literal);

void	ScalarConverter::convert(const std::string &literal)
{
	LiteralType	type = detectType(literal);

	if (type == INVALID)
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: impossible\n"
					<< "double: impossible\n";
		return ;
	}

	double	value = 0.0;

	try
	{
		switch (type)
		{
		case PSEUDO:
			value = parsePseudo(literal);
			break;
		case CHAR:
			value = parseChar(literal);
			break;
		case INT:
			value = parseInt(literal);
			break;
		case FLOAT:
			value = parseFloat(literal);
			break;
		case DOUBLE:
			value = parseDouble(literal);
			break;
		default:
			break;
		}
	}
	catch(...)
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: impossible\n"
					<< "double: impossible\n";
		return ;
	}

	char	c;
	int		i;

	CharStatus	charStatus = getCharFromDouble(value, c);
	bool		intOk = getIntFromDouble(value, i);
	float		f = getFloatFromDouble(value);
	double		d = getDoubleFromDouble(value);

	printChar(charStatus, c);
	printInt(intOk, i);
	printFloat(f);
	printDouble(d);
}

LiteralType	detectType(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		return (PSEUDO);
	if (isCharLiteral(literal))
		return (CHAR);
	if (isIntLiteral(literal))
		return (INT);
	if (isFloatLiteral(literal))
		return (FLOAT);
	if (isDoubleLiteral(literal))
		return (DOUBLE);
	return (INVALID);
}

////////////////////////////////////////////////////////////////////////////////

// 1. Detect the literal type (LEXING)
// 2. Parse literal → real numeric value (convert everything into double first)
//								(string → double → char / int / float / double)
// 3. Cast double → other scalar types(safely)
// 4. Print results (exact format)