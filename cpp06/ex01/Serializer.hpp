#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include "Colors.hpp"

struct Data
{
	int			i;
	double		d;
	std::string	str;
};

class Serializer
{
private:
	Serializer() = delete;

	Serializer(const Serializer &other) = delete;
	Serializer &operator=(const Serializer &other) = delete;

	Serializer(Serializer &&other) noexcept = delete;
	Serializer &operator=(Serializer &&other) noexcept = delete;

	~Serializer() = default;

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif