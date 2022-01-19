#ifndef STRING_FUNCTION_HPP
#define STRING_FUNCTION_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

bool		is_whitespace(char c);
void		erase_white_space(std::string &str_equation);
std::string	double_to_string(double number, int precision = 6);

#endif