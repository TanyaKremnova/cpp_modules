#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{

	return(reinterpret_cast<uintptr_t>(ptr));
}
Data*	Serializer::deserialize(uintptr_t raw)
{

	return(reinterpret_cast<Data*>(raw));
}

////////////////////////////////

// reinterpret_cast means:
// “Do not change the bits. Just reinterpret them as another type.”
//  - No conversion.
//  - No transformation.
//  - No safety checks.

// Why it’s unsafe
//  - The compiler cannot verify correctness
//  - The address may become invalid
//  - The object may no longer exist
//  - Aliasing rules can be violated

////////////////////////////////
