#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

class Sed
{
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;

	bool		readFile(std::string& content) const;
	std::string	replaceAll(const std::string &content) const;
	bool		writeFile(const std::string &result) const;

public:
	Sed(const std::string &filename,
		const std::string &s1,
		const std::string &s2);

	~Sed();

	bool	process() const;
};

#endif