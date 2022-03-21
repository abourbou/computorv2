
#include <parsing.hpp>
#include "string_function.hpp"
#include "Singleton.hpp"
#include "Map_variable.hpp"

void	help_command(void)
{
	std::string help_str = UWhite
				BWhite		"\tComputorv2 is a none-basic calculator\n\n" Color_Off
				BWhite		"\tIt supports :\n"
				Color_Off	"\t- real numbers, complex numbers and matrix\n"
				BGreen		"\tex: " Color_Off "4 / 2i / [[2,0];[4,-9]]\n"
				Color_Off	"\t- operators + - * / % ^ and matrix multiplication with ** symbol,\n"
							"\t  you can also use () for priority operations\n\n"
				BWhite		"\tIt can :\n"
				Color_Off	"\t- perform computation\n" 
				BGreen		"\tex: \n"
				Color_Off	"\t> (4 + 2i) * 3 =?\n"
				BYellow		"\t12 + 6i\n"
				Color_Off	"\t- stock variable\n"
				BGreen		"\tex:\n"
				Color_Off	"\t> a = 4\n"
				BYellow		"\t4\n" 
				Color_Off	"\t> a * 2 =?\n"
				BYellow		"\t8\n"
				Color_Off	"\t- stock functions\n"
				BGreen		"\tex: \n"
				Color_Off	"\t> f(x) = x + (5 - x) ^ 2\n"
				BBlue		"\tx + (5 - x) ^ 2\n"
				Color_Off	"\t- resolve polynom of 2 or less degree\n"
				BGreen		"\tex: " Color_Off "x^2 - x = 5?\n\n"
				BWhite		"\tbasic variables and functions are already implemented :\n"
				Color_Off	"\t- var : i, pi, e\n"
				Color_Off	"\t- fct : sqrt, abs, norm, sin, cos, tan, exp, ln, log\n\n"
				BWhite		"\tyou can perform commands:\n"
				Color_Off	"\t- exit          : quit the program\n"
				Color_Off	"\t- list-variable : show the list of var and fct in the program\n"
				Color_Off	"\t- chg-angle-mod : change angle unit\n"
				Color_Off	"\t- help          : show informations about the program\n"
				Color_Off	"\t- test          : test if the program respond\n";

	std::cout << help_str << std::endl;
}

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
	else if (line == "HELP")
		help_command();
	else
		throw std::runtime_error("unknown command");
}