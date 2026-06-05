#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonepook;
	std::string	command;

	std::cout << "\nWelcome to The PhoneBook!\n";
	std::cout << "Available commands: ADD | SEARCH | EXIT\n";

	while (true)
	{
		std::cout << "\nEnter command: ";
		std::getline(std::cin, command);

		if (std::cin.eof())
			break;
		
		if (command == "ADD")
			phonepook.addContact();
		else if (command == "SEARCH")
			phonepook.searchContact();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			continue;
	}
	return (0);
}