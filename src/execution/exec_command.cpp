
#include <parsing.hpp>
#include "string_function.hpp"
#include "singleton.hpp"

void	exec_command(std::string line)
{
	Singleton *glob_var = Singleton::GetInstance();

	to_upper(line);
	if (line == "EXIT")
		glob_var->set_exit(true);
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