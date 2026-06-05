#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#  define RED "\033[0;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class Fixed
{
private:
	int					_fixedPointNum;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other); // copy constructor
	Fixed &operator=(const Fixed &other); // copy assignment operator overload
	~Fixed();

	Fixed(const int num);
	Fixed(const float num);

	int		getRawBits( void ) const; //returns the raw value of the fixed-point value
	void	setRawBits( int const raw ); //sets the raw value of the fixed-point number

		// ---------------------------Exercise 01--------------------------- //

	float	toFloat( void ) const; //converts the fixed-point value to a floating-point value
	int		toInt( void ) const; //converts the fixed-point value to an integer value

		// ---------------------------Exercise 02--------------------------- //

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	Fixed	&operator++(); //Prefix ++a
	Fixed	operator++(int num); //Postfix a++
	Fixed	&operator--(); //Prefix --a
	Fixed	operator--(int num); //Postfix a--

	static			Fixed &min(Fixed &fixedA, Fixed &fixedB);
	static const	Fixed &min(const Fixed &fixedA, const Fixed &fixedB);
	static			Fixed &max(Fixed &fixedA, Fixed &fixedB);
	static const	Fixed &max(const Fixed &fixedA, const Fixed &fixedB);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif