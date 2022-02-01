#pragma once
#ifndef STRING_FUNCTION_HPP
#define STRING_FUNCTION_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

bool		is_whitespace(char c);
void		erase_white_space(std::string &str_equation);
std::string	double_to_string(double number, int precision = 6);
void		to_upper(std::string &str);
bool		is_alpha(std::string str);

#endif