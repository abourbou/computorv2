
#include <parsing.hpp>
#include "string_function.hpp"
#include "Singleton.hpp"
#include "Map_variable.hpp"

void	exec_command(std::string line)
{
	static Singleton *glob_var = Singleton::GetInstance();
	static Map_variable &map = glob_var->get_map_variable();

	to_upper(line);
	if (line == "EXIT")
		glob_var->set_exit(true);
	else if (line == "LIST-VARIABLE")
		map.show_map();
	else if (line == "TEST")
		std::cout << "this is a test command" << std::endl;
	else if (line == "CHG-ANGLE-MOD")
	{
		glob_var->change_angle_mod();
		if (glob_var->is_radian())
			std::cout << "Angle is in radians now" << std::endl;
		else
			std::cout << "Angle is in degrees now" << std::endl;
	}
	else
	{
		throw(std::runtime_error("Unvalid command"));
	}
}