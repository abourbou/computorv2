
#include <iostream>
#include "execution.hpp"

void	test_syntax(void)
{
	std::cout << std::endl << "*********INTO TEST SYNTAX**********" << std::endl;
	exec_line("var = 5");
	std::cout << std::endl;
	exec_line("x = 23edd23-+-+");
	std::cout << std::endl;
	exec_line("a ==?");
	std::cout << std::endl;
	exec_line("a42 = 5");
	std::cout << std::endl;
	exec_line("x == 2");
	std::cout << std::endl;
	exec_line("a = b = c");
	std::cout << std::endl;
	exec_line("42 + 5! =?");
	std::cout << std::endl;
	exec_line("4 = 5 =?");
	std::cout << std::endl;
	exec_line("4 = 5 ?");
	std::cout << std::endl;
}