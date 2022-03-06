
#include <iostream>
#include "execution.hpp"

void	test_input(void)
{
	bool exit;

	std::cout << "into test imput" << std::endl;
	exec_line("var = 5", exit);
	std::cout << std::endl;
	exec_line("x = 23edd23-+-+", exit);
	std::cout << std::endl;
}