#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0)
{
	std::cout	<< BLUE
				<< "Default constructor called\n"
				<< RESET;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout	<< BLUE
				<< "Copy constructor called\n"
				<< RESET;
	_fixedPointNum = other._fixedPointNum;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout	<< BLUE
				<< "Copy assignment operator called\n"
				<< RESET;
	if (this != &other)
		_fixedPointNum = other._fixedPointNum;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout	<< RED
				<< "Destructor called\n"
				<< RESET;
}

Fixed::Fixed(const int num)
{
	std::cout	<< BLUE
				<< "Int constructor called\n"
				<< RESET;
	_fixedPointNum = num * (1 << _fractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout	<< BLUE
				<< "Float constructor called\n"
				<< RESET;
	_fixedPointNum = round(num * (1 << _fractionalBits));
}

int	Fixed::getRawBits( void ) const
{
	std::cout	<< "getRawBits member function called\n";
	return (_fixedPointNum);
}

void	Fixed::setRawBits( int const raw )
{
	_fixedPointNum = raw;
}


		// ---------------------------Exercise 01--------------------------- //


float	Fixed::toFloat( void ) const
{
	float	real_num;

	real_num = static_cast<float>(_fixedPointNum) / (static_cast<float>(1 << _fractionalBits));
	return (real_num);
}

int	Fixed::toInt( void ) const
{
	int	integer_part;

	integer_part = _fixedPointNum / (1 << _fractionalBits);
	return (integer_part);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}