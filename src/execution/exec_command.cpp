
#include <parsing.hpp>

void	exec_command(std::string line, bool &exit)
{
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