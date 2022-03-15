#pragma once

#include "parsing.hpp"

void	exec_line(std::string line);
void	exec_task(Task task, std::string line);
void	exec_command(std::string line);
void	exec_assign_var(std::string line);
void	exec_assign_fct(std::string line);
void	exec_computation(std::string line);