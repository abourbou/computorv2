
#ifndef computorv1_functions_HPP
# define computorv1_functions_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

void		erase_white_space(std::string &str_equation);
bool		is_a_float(float number);
float		ft_abs(float number);
double		ft_sqrt(double number);
std::string	float_to_string(float number, int precision = 6);

#endif