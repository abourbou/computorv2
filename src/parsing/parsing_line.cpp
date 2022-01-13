#include "parsing.hpp"

/**
 * @brief check if the line doesn't have forbidden character + put it in a correct way
 * 
 * @param line 
 * @return std::string 
 */

std::string	regulate_string(std::string line)
{
	std::string	allowed_symboles("+-*/%()[],;=?");

	auto it = line.begin();
	while (it < line.end())
	{
		char &c = *it;
		if (!isalnum(c) && allowed_symboles.find(c) == std::string::npos && !isspace(c))
			throw(ForbiddenCharacter());
		c = toupper(c);
		if (isspace(c) && it + 1 != line.end() && isspace(*(it + 1)))
		{
			auto start = it + 1;
			auto end = it + 1;
			while(end != line.end() && isspace(*end))
				++end;
			line.erase(start, end);
		}
		++it;
	}
	if (isspace(*line.begin()))
		line.erase(line.begin());
	if (isspace(*line.end()))
		line.erase(line.end());
	return(line);
}

int		find_task(std::string line)
{
	std::cout << "line : " << line << std::endl;
	return (Command);
}
