#include "Sed.hpp"

bool	Sed::process() const
{
	std::string	content;
	std::string	result;

	if (_filename.empty() || _s1.empty())
		return (false);
	if (!readFile(content))
		return (false);
	result = replaceAll(content);
	if (!writeFile(result))
		return (false);
	return (true);
}

bool	Sed::readFile(std::string &content) const
{
	std::string		line;

	std::ifstream ifs(_filename);
	if (!ifs)
		return (false);
	while (std::getline(ifs, line))
	{
		content += line;
		if (!ifs.eof())
			content += "\n";
	}
	return (true);
}

std::string	Sed::replaceAll(const std::string &content) const
{
	std::string	result;
	std::size_t	pos = 0;
	std::size_t	found = 0;

	while (true)
	{
		found = content.find(_s1, pos);
		if (found == std::string::npos)
			break;
		result += content.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += content.substr(pos);
	return (result);
}

bool	Sed::writeFile(const std::string &result) const
{
	std::string	outname;

	outname = _filename + ".replace";
	std::ofstream ofs(outname);
	if (!ofs)
		return (false);
	ofs << result;
	return (true);
}

// ✅ 7. Create Tests

// Make a test folder with input files:
// - Test cases to include:
// - file with multiple occurrences
// - file with no occurrences
// - file with s1 equal to s2
// - s1 longer than s2
// - s1 shorter than s2
// - s1 at beginning / end of file
// - empty file
// - missing file (should give error)
// - empty s1 (should give error)

// Tests you should write (and run)

// Normal case: small file where s1 appears multiple times in lines.
// s1 not present — output should equal input.
// s1 at beginning or end of file.
// s1 equal to s2.
// s1 is empty — program must detect and show error (no crash).
// filename does not exist — proper error message.
// Very large file (optional) to check memory/time.
// s1 contains special characters (spaces, punctuation).
// s1 longer than file content — no replacements; output equals input.
// File with multiple consecutive s1 occurrences (ensure no skipping).