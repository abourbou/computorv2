#include "parsing.hpp"
#include "string_function.hpp"

/**
 * @brief check if the line doesn't have forbidden character + put it in a correct way
 *
 * @param line
 * @return std::string
 */

std::string	regulate_string(std::string line)
{
	std::string	allowed_symboles("+-*/%^()[],;=?");

	auto it = line.begin();
	while (it < line.end())
	{
		char &c = *it;
		if (!isalnum(c) && allowed_symboles.find(c) == std::string::npos && !isspace(c))
			throw(std::runtime_error("Forbidden character"));
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
	erase_white_space(line);
	return(line);
}

/**
 * @brief Find the task asked :
 * assignation, computation, resolution equation etc...
 *
 * @param line
 * @return int
 */
int		find_task(std::string line)
{
	auto nb_equal = std::count(line.begin(), line.end(), '=');
	if (nb_equal == 0)
		return (Command);
	else if (nb_equal == 1)
	{
		auto nb_interrogation = std::count(line.begin(), line.end(), '?');
		auto it_equal = std::find(line.begin(), line.end(), '=');
		if (nb_interrogation == 0)
		{
			if (std::count(line.begin(), it_equal, '(' ) > 0 ||
				std::count(line.begin(), it_equal, ')') > 0)
				return(Assign_func);
			return(Assign_var);
		}
		else if (nb_interrogation == 1)
		{
			auto it_interrog = std::find(line.begin(), line.end(), '?');
			if (it_interrog + 1 != line.end())
				throw(std::runtime_error("? symbol must be at the end of the command"));
			if (it_equal + 1 == it_interrog)
				return (Computation);
			return (Resolv_Polyn);
		}
		throw(std::runtime_error("more than one question mark sign"));
	}
	else
	{
		throw(std::runtime_error("More than one equal sign"));
	}
	return (Assign_func);
}
