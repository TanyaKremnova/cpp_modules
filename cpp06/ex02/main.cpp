#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	std::srand(std::time(NULL));

	Base*	p = generate();

	identify(p);
	identify(*p);

	delete p;

	return (0);
}