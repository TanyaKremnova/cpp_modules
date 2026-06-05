#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Usege: ./convert <literal>\n";
		return (EXIT_FAILURE);
	}

	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}

// static_cast is a compile-time checked conversion.
// It tells the compiler:
// “I know this conversion is valid.”
// ___________________________________________________
// Rule of thumb for static_cast

// ✅ Use when:
// You convert numbers
// You convert char ↔ int
// You upcast (Derived → Base)
// You know the type at compile time

// ❌ Do NOT use when:
// You are unsure about the real dynamic type
// You are downcasting polymorphic objects
// ___________________________________________________

// Where static_cast is used (GOOD)
// 1. Numeric conversions
// double d = 42.5;
// int i = static_cast<int>(d);

// 2. Enum ↔ integer
// enum Type { A, B };
// int x = static_cast<int>(A);

// 3. Upcasting (derived → base)
// class Base {};
// class Derived : public Base {};
// Derived d;
// Base* b = static_cast<Base*>(&d); // SAFE
// Upcasting is always safe.

// 4. Explicit intent instead of implicit conversion
// char c = static_cast<char>(value);

//////////////////////////////////////////////////////////

// dynamic_cast is a runtime-checked cast.
// It asks:
// “Is this object really of that type?”

// ✅ Typical real-world use case
// void handle(Base* b)
// {
//     if (Derived* d = dynamic_cast<Derived*>(b)) {
//         d->special();
//     }
// }

// ✅ Used when:
// You have a polymorphic hierarchy
// You genuinely don’t know the dynamic type

// Where dynamic_cast is NOT appropriate
// ❌ Numeric conversions
// ❌ Non-polymorphic types
// ❌ Performance-critical code
// ❌ When design should avoid type checks