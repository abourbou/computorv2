#ifndef COMPUTATION
# define COMPUTATION

#include <utility>
#include <list>
#include <string>
#include <iostream>

enum class block_type
{
	math_operator,
	litteral_value,
	variable,
	math_function,
	parenthesis,
};
typedef std::pair<block_type, std::string> block;

std::list<block>	cmd_into_list(std::string cmd);


#endif