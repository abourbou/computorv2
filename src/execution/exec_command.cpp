
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
		std::cout << BGreen "this is a test command" Color_Off << std::endl;
	else if (line == "CHG-ANGLE-MOD")
	{
		glob_var->change_angle_mod();
		if (glob_var->is_radian())
			std::cout << BWhite "Angle is in radians now" Color_Off << std::endl;
		else
			std::cout << BWhite "Angle is in degrees now" Color_Off << std::endl;
	}
	else
		throw std::runtime_error("unknown command");
}