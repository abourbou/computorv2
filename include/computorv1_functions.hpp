
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
bool		is_an_int(double number);
double		ft_abs(double number);
double		ft_sqrt(double number);
std::string	double_to_string(double number, int precision = 6);

#endif