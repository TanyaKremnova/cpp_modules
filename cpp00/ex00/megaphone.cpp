#include <iostream>
#include <cctype>
#include <string>
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

class Megaphone
{
private:
	std::string	toUpper(const std::string &input) const;

public:
	Megaphone();
	~Megaphone();

	void	shout(int argc, char **argv) const;
};

Megaphone::Megaphone()
{
}

Megaphone::~Megaphone()
{
}

std::string Megaphone::toUpper(const std::string &input) const
{
	std::string	result;

	for (char c : input) // for each char c in arg (range-based loop)
		result += static_cast<char>(std::toupper(c));

	return (result);
}

void	Megaphone::shout(int argc, char **argv) const
{
	if (argc == 1)
	{
		std::cout	<< MAGENTA
					<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
					<< RESET
					<< std::endl;
		return;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		std::cout	<< MAGENTA
					<< toUpper(arg)
					<< RESET;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	Megaphone	megaphone;
	megaphone.shout(argc, argv);
	return (0);
}

////////////// megaphone.cpp //////////////

// #include <iostream>
// #include <cctype>
// #include <string>

// class Megaphone
// {
// private:
// 	std::string arg;
	
// public:
// 	Megaphone();
// 	~Megaphone();
// };

// Megaphone::Megaphone() : arg("")
// {
// }

// Megaphone::~Megaphone()
// {
// }

// int	main(int argc, char **argv)
// {
// 	Megaphone	megaphone;
// 	int			i = 1;
	
// 	if (argc == 1)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
// 			return (0);
// 	}
// 	while (i < argc)
// 	{
// 		std::string arg = argv[i];
// 		for (char c : arg)
// 			std::cout << static_cast<char>(std::toupper(c));
// 		i++;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }