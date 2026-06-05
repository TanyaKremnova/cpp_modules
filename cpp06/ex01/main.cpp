#include "Serializer.hpp"

int	main()
{
	Data	data;

	data.i = 42;
	data.d = 4.2;
	data.str = "hello";

	// Original pointer
	Data*	originalPtr = &data;

	// Serialize
	uintptr_t	raw = Serializer::serialize(originalPtr);

	// Deserialize
	Data*	restoredPtr = Serializer::deserialize(raw);

	// Tests
	std::cout	<< "Original pointer : "
				<< originalPtr
				<< std::endl;

	std::cout	<< "Serialized value : "
				<< raw
				<< std::endl;

	std::cout	<< "Restored pointer : "
				<< restoredPtr
				<< std::endl;

	if (originalPtr == restoredPtr)
		std::cout	<< GREEN
					<< "Pointers match\n\n"
					<< RESET;
	else
		std::cout	<< RED
					<< "Pointers do NOT match\n\n"
					<< RESET;

	// Access through restored pointer
	std::cout	<< "restoredPtr->i   = " << restoredPtr->i << std::endl;
	std::cout	<< "restoredPtr->d   = " << restoredPtr->d << std::endl;
	std::cout	<< "restoredPtr->str = " << restoredPtr->str << std::endl;

	////////////////////////////////////////////////////////////////////////
	////////////////////////// Example of danger: //////////////////////////
	// Data*	dangerPtr = &data;

	// uintptr_t	raw1 = Serializer::serialize(dangerPtr);
	// delete dangerPtr;
	// Data*	bad = Serializer::deserialize(raw1); // invalid pointer
	////////////////////////////////////////////////////////////////////////

	return (0);
}