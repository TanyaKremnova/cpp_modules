#include "PhoneBook.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("")
{
	std::cout << "Class Contact created\n";
}

Contact::~Contact()
{
	std::cout << "Class Contact destroyed\n";
}

static std::string	promptField(const std::string &message)
{
	std::string	input;

	while (true)
	{
		std::cout << message;

		if (!std::getline(std::cin, input))
		{
			std::cout << "\nInput aborted.\n";
			return ("");
		}
		if (!input.empty())
			return(input);

		std::cout << "Field cannot be empty. Please try again.\n";
	}
}

void	Contact::setContact()
{
	firstName = promptField("Enter first name: ");
	lastName = promptField("Enter last name: ");
	nickname = promptField("Enter nickname: ");
	phoneNumber = promptField("Enter phone number: ");
	darkestSecret = promptField("Enter darkest secret: ");
}

static std::string	truncateStr(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::displayShort(int index) const
{
	std::cout << "|" << std::setw(10) << index << "|"
				<< std::setw(10) << truncateStr(firstName) << "|"
				<< std::setw(10) << truncateStr(lastName) << "|"
				<< std::setw(10) << truncateStr(nickname) << "|"
				<< std::endl;
}

void	Contact::displayFull() const
{
	std::cout << "\n----------- Contact Information -----------\n";
	std::cout << "First Name:     " << firstName << std::endl;
	std::cout << "Last Name:      " << lastName << std::endl;
	std::cout << "Nickname:       " << nickname << std::endl;
	std::cout << "Phone Number:   " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << "-------------------------------------------\n";
}