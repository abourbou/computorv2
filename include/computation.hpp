#ifndef COMPUTATION
# define COMPUTATION

#include <utility>
#include <list>
#include <string>
#include <iostream>
#include "string_function.hpp"

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

using token = std::pair<token_type, std::string>;

std::list<token>	lexer(std::string cmd);


#endif