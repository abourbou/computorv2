
#include <parsing.hpp>
#include "string_function.hpp"

void	exec_command(std::string line, bool &exit)
{
	to_upper(line);
	if (line == "EXIT")
		exit = true;
	else if (line == "HISTORY" || line == "CHANGLE-ANGLE-MOD"
				|| line == "LIST-VARIABLE")
	{
		std::cout << "This feature is not implemented yet" << std::endl;
	}
	else
	{
		throw(std::runtime_error("Unvalid command"));
	}
}