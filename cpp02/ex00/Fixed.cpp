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

int	Fixed::getRawBits( void ) const
{
	std::cout	<< "getRawBits member function called\n";
	return (_fixedPointNum);
}

void	Fixed::setRawBits( int const raw )
{
	_fixedPointNum = raw;
}