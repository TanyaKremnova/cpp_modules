#include "Point.hpp"

int	main( void )
{
	Point	A(0, 0);
	Point	B(4, 0);
	Point	C(2, 4);

	std::cout	<< "\n=== Point INSIDE ===\n";
	std::cout	<< GREEN
				<< "Inside: "
				<< bsp(A, B, C, Point(2, 1))
				<< " (expected true)\n\n"
				<< RESET;

	std::cout	<< "=== Point OUTSIDE ===\n";
	std::cout	<< RED
				<< "Outside: "
				<< bsp(A, B, C, Point(5, 1))
				<< " (expected false)\n\n"
				<< RESET;

	std::cout	<< "=== Point ON EDGE ===\n";
	std::cout	<< YELLOW
				<< "On edge: "
				<< bsp(A, B, C, Point(2, 0))
				<< " (expected false)\n\n"
				<< RESET;

	std::cout	<< "=== Point ON VERTEX ===\n";
	std::cout	<< YELLOW
				<< "On vertex: "
				<< bsp(A, B, C, Point(0, 0))
				<< " (expected false)\n\n"
				<< RESET;


	std::cout	<< "=== Negative coordinates ===\n";
	Point	A2(-2, 0);
	Point	B2(2, 0);
	Point	C2(0, 2);
	Point	P_neg(-1, 1);

	std::cout	<< GREEN
				<< "Negative coordinates inside: "
				<< bsp(A2, B2, C2, P_neg)
				<< " (expected true)\n\n"
				<< RESET;

	std::cout	<< "=== Very small Fixed values ===\n";
	Point	A3(0.0f, 0.0f);
	Point	B3(0.1f, 0.0f);
	Point	C3(0.0f, 0.1f);
	Point	P_small(0.002f, 0.002f);

	std::cout	<< GREEN
				<< "Small fixed inside: "
				<< bsp(A3, B3, C3, P_small)
				<< " (expected true)\n\n"
				<< RESET;
	return (0);
}