
#include <parsing.hpp>
#include "string_function.hpp"
#include "Singleton.hpp"
#include "Map_variable.hpp"

void	exec_command(std::string line)
{
	Singleton *glob_var = Singleton::GetInstance();

	to_upper(line);
	if (line == "EXIT")
		glob_var->set_exit(true);
	else if (line == "LIST-VARIABLE")
	{
		Map_variable &map = Singleton::GetInstance()->get_map_variable();
		map.show_map();
	}
	else if (line == "TEST")
		std::cout << "this is a test command" << std::endl;
	else if (line == "CHANGLE-ANGLE-MOD")
	{
		std::cout << "This feature is not implemented yet" << std::endl;
	}
	else
	{
		throw(std::runtime_error("Unvalid command"));
	}
}