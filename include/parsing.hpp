#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <list>
#include "string_function.hpp"
#include "IToken.hpp"
#include "Token_function.hpp"
#include "Token_operator.hpp"
#include "Token_parenth.hpp"
#include "Token_value.hpp"
#include "Token_variable.hpp"

enum Task {
	Command,
	Assign_var,
	Assign_func,
	Computation,
	Resolv_Polyn
};

using pre_token = std::pair<token_type, std::string>;


std::string	regulate_string(std::string line);
Task		find_task(std::string line);
void		exec_command(std::string line);
void		exec_assign_value(std::string line);
std::list<IToken *>	lexer(std::string cmd);
