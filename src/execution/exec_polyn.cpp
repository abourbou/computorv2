
#include <string>
#include <iostream>
#include "Polyn_equation.hpp"

void	exec_polyn(std::string line)
{
	line.pop_back();

	Polyn_Equation polyn(line);
}