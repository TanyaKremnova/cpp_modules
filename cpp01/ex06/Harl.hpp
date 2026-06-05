#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

#  define RED "\033[3;31m"
#  define GREEN "\033[0;32m"
#  define YELLOW "\033[0;33m"
#  define BLUE "\033[0;34m"
#  define MAGENTA "\033[0;35m"
#  define CYAN "\033[0;36m"
#  define RESET "\033[0m"

class Harl
{
private:
	void	debug( void ); // non-inline member functions
	void	info( void ); // declared in the class
	void	warning( void ); // defined outside, typically in a .cpp file
	void	error( void );

public:
	Harl();
	~Harl();

	void	complain( std::string level );
};

#endif

// If the functions were inline, the compiler might not generate
// a real function address — the function may be copied at each call site instead.
// Then pointers would be impossible or meaningless.

// class Harl
// {
// public:
//     void debug() {               // <-- inline (defined inside class)
//         std::cout << "debug\n";
//     }
// };
