
#include <parsing.hpp>

void	exec_command(std::string line, bool &exit)
{
	std::cout << "line in exec_command : " << line << std::endl;
	if (line == "EXIT")
		exit = true;
}