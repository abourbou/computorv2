#ifndef COMPUTATION
# define COMPUTATION

#include <utility>
#include <list>
#include <string>
#include <iostream>

enum class token_type
{
	math_operator,
	litteral_value,
	variable,
	math_function,
	parenthesis,
};

using token = std::pair<token_type, std::string>;

std::list<token>	lexer(std::string cmd);


#endif