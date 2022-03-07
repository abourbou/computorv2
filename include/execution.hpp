#ifndef EXECUTION_HPP
# define EXECUTION_HPP

#include "parsing.hpp"

void	exec_line(std::string line, bool &exit);
void	exec_task(Task task, bool &exit, std::string line);

#endif