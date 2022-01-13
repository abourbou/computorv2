#ifndef PARSING_HPP
# define PARSING_HPP

#include <cctype>
#include "exception_classes.hpp"
#include <string>
#include <iostream>

enum Task {Command, Assign_var, Assign_func, Computation, Resolv_Polyn};

std::string	regulate_string(std::string line);
int			find_task(std::string line);

#endif