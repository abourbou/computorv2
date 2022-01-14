#ifndef PARSING_HPP
# define PARSING_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

enum Task {
	Command,
	Assign_var,
	Assign_func,
	Computation,
	Resolv_Polyn
};

std::string	regulate_string(std::string line);
int			find_task(std::string line);
void		exec_command(std::string line, bool &exit);

#endif