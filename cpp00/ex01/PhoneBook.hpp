#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
#  define YELLOW "\033[1;33m"
#  define RESET "\033[0m"


/**
 * @class Contact
 * @brief Represents an individual contact stored in the PhoneBook.
 * 
 * #### Private Attributes:
 * 
 * - std::string firstName;
 * 
 * - std::string lastName;
 * 
 * - std::string nickname;
 * 
 * - std::string phoneNumber;
 * 
 * - std::string darkestSecret;
 *
 * #### Public Methods:
 * 
 * - void setContact(); Prompts the user to fill in all fields.
 * 
 * - void displayShort(int index) const; Prints the contact in table format.
 * 
 * - void displayFull() const; Displays all stored details.
 */
class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact();
	~Contact();

	void	setContact();
	void	displayShort(int index) const;
	void	displayFull() const;
};

/**
 * @class PhoneBook
 * @brief Stores and manages up to 8 contacts in memory.
 * 
 * The PhoneBook class allows adding, searching, and displaying contacts.
 * When more than 8 contacts are added, the oldest one is replaced.
 * 
 * #### Private Attributes:
 * 
 * - Contact contacts[8]; Array of stored contacts (max 8)
 * 
 * - int totalContacts; Number of contacts currently stored
 * 
 * - int nextIndex; Next position to overwrite when adding a new contact
 *
 * #### Public Methods:
 * 
 * - void addContact();
 * 
 * - void searchContact() const;
 * 
 * - void displayAll() const;
 */
class PhoneBook
{
private:
	Contact	contacts[8];
	int		totalContacts;
	int		nextIndex;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact() const;
};

#endif