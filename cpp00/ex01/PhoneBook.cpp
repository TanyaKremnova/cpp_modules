#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0)
{
	std::cout << "Class PhoneBook created\n";
}

PhoneBook::~PhoneBook()
{
	std::cout << "Class PhoneBook destroyed\n";
}

void	PhoneBook::addContact()
{
	contacts[nextIndex].setContact();

	if (totalContacts < 8)
		totalContacts++;
	nextIndex = (nextIndex + 1) % 8;
}

void	PhoneBook::searchContact() const
{
	std::string	input;
	int			index;

	if (totalContacts == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first!\n";
		return;
	}

	std::cout	<< std::endl
				<< YELLOW
				<< "---------------------------------------------\n"
				<< "|     Index|First Name| Last Name|  Nickname|\n"
				<< "---------------------------------------------\n";

	for (int i = 0; i < totalContacts; i++)
		contacts[i].displayShort(i);

	std::cout	<< "---------------------------------------------\n"
				<< RESET;

	std::cout << "Enter index to view details: ";
	std::getline(std::cin, input);

	if (std::cin.eof())
		return;
	
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		index = input[0] - '0';
		if (index >= 0 && index < totalContacts)
			contacts[index].displayFull();
		else
			std::cout << "Invalid index!\n";
	}
	else
		std::cout << "Invalid input!\n";
}