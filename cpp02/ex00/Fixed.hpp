#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
	static const int	_fractionalBits = 8; // the class property

public:
	Fixed();
	Fixed(const Fixed &other); // copy constructor
	Fixed &operator=(const Fixed &other); // copy assignment operator overload
	~Fixed();

	int		getRawBits( void ) const; //returns the raw value of the fixed-point value
	void	setRawBits( int const raw ); //sets the raw value of the fixed-point number
};

#endif