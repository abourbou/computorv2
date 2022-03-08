#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <list>
#include "string_function.hpp"

enum Task {
	Command,
	Assign_var,
	Assign_func,
	Computation,
	Resolv_Polyn
};

enum class token_type
{
	math_operator,
	variable,
	math_function,
	parenthesis,
	rational_value,
	complex_value,
	matrix_value,
};

using pre_token = std::pair<token_type, std::string>;


std::string	regulate_string(std::string line);
Task		find_task(std::string line);
void		exec_command(std::string line);
void		exec_assign_value(std::string line);
std::list<pre_token>	lexer(std::string cmd);
