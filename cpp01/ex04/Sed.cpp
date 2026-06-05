#include "Sed.hpp"

Sed::Sed(const std::string &filename,
		const std::string &s1,
		const std::string &s2)
	: _filename(filename), _s1 (s1), _s2 (s2)
{
}

Sed::~Sed()
{
}