#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>

class Base
{
public:
	virtual ~Base() = default;
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

// RTTI (Run-Time Type Information)
// RTTI exists so the program can answer: “What is the real type of this object right now?”

// Why dynamic_cast is safe: 
// A* a = dynamic_cast<A*>(basePtr);
// 1. Runtime-checked
// 2. Never produces invalid pointers
// 3. Failure is detectable

// Use dynamic_cast only when:
// 1. The class is polymorphic
// 2. You genuinely do not know the derived type
// 3. Behavior depends on the real type
// 4. Design constraints prevent virtual dispatch