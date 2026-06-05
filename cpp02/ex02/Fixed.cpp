#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNum(0)
{
	// std::cout	<< BLUE
	// 			<< "Default constructor called\n"
	// 			<< RESET;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout	<< BLUE
	// 			<< "Copy constructor called\n"
	// 			<< RESET;
	_fixedPointNum = other._fixedPointNum;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout	<< BLUE
	// 			<< "Copy assignment operator called\n"
	// 			<< RESET;
	if (this != &other)
		_fixedPointNum = other._fixedPointNum;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout	<< RED
	// 			<< "Destructor called\n"
	// 			<< RESET;
}

Fixed::Fixed(const int num)
{
	// std::cout	<< BLUE
	// 			<< "Int constructor called\n"
	// 			<< RESET;
	_fixedPointNum = num * (1 << _fractionalBits);
}

Fixed::Fixed(const float num)
{
	// std::cout	<< BLUE
	// 			<< "Float constructor called\n"
	// 			<< RESET;
	_fixedPointNum = round(num * (1 << _fractionalBits));
}

int	Fixed::getRawBits( void ) const
{
	// std::cout	<< "getRawBits member function called\n";
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


		// ---------------------------Exercise 02--------------------------- //


bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointNum > other._fixedPointNum);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointNum < other._fixedPointNum);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointNum >= other._fixedPointNum);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointNum <= other._fixedPointNum);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointNum == other._fixedPointNum);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointNum != other._fixedPointNum);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	sum;

	sum._fixedPointNum = this->_fixedPointNum + other._fixedPointNum;
	return (sum);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	dif;

	dif._fixedPointNum = this->_fixedPointNum - other._fixedPointNum;
	return (dif);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	mult;
	int64_t	tmp;

	tmp = (int64_t)this->_fixedPointNum * (int64_t)other._fixedPointNum;
	mult._fixedPointNum = tmp >> _fractionalBits;
	return (mult);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	div;

	div._fixedPointNum = (this->_fixedPointNum << _fractionalBits) / other._fixedPointNum;
	return (div);
}

Fixed	&Fixed::operator++()//Prefix ++a
{
	this->_fixedPointNum += 1;
	return (*this);
}

Fixed	Fixed::operator++(int num) //Postfix a++ // (int num) is a dummy integer parameter
{
	Fixed	tmp;
	(void)num;

	tmp._fixedPointNum = this->_fixedPointNum;
	this->_fixedPointNum += 1;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPointNum -=1;
	return(*this);
}

Fixed	Fixed::operator--(int num)
{
	Fixed	tmp;
	(void)num;

	tmp._fixedPointNum = this->_fixedPointNum;
	this->_fixedPointNum -= 1;
	return (tmp);
}

Fixed &Fixed::min(Fixed &fixedA, Fixed &fixedB)
{
	if (fixedA < fixedB) //It calls: bool Fixed::operator<(const Fixed &other) const;
		return (fixedA);
	return (fixedB);
}

const	Fixed &Fixed::min(const Fixed &fixedA, const Fixed &fixedB)
{
	if (fixedA < fixedB)
		return (fixedA);
	return (fixedB);
}

Fixed &Fixed::max(Fixed &fixedA, Fixed &fixedB) //It calls: bool Fixed::operator>(const Fixed &other) const;
{
	if (fixedA > fixedB)
		return (fixedA);
	return (fixedB);
}

const	Fixed &Fixed::max(const Fixed &fixedA, const Fixed &fixedB)
{
	if (fixedA > fixedB)
		return (fixedA);
	return (fixedB);
}