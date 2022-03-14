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

std::string	regulate_string(std::string line);
Task		find_task(std::string line);
std::list<IToken *>	lexer(std::string cmd);
void				clean_lexer(std::list<IToken*> list_tok);
const IValue *computation(const std::list<IToken*> list_token);