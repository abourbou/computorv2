
#include <iostream>
#include "execution.hpp"

void	test_syntax(void)
{
	bool exit;

	std::cout << "into test imput" << std::endl;
	exec_line("var = 5", exit);
	std::cout << std::endl;
	exec_line("x = 23edd23-+-+", exit);
	std::cout << std::endl;
	exec_line("a ==?", exit);
	std::cout << std::endl;
	exec_line("a42 = 5", exit);
	std::cout << std::endl;
	exec_line("x == 2", exit);
	std::cout << std::endl;
	exec_line("a = b = c", exit);
	std::cout << std::endl;
	exec_line("42 + 5! =?", exit);
	std::cout << std::endl;
	exec_line("4 = 5 =?", exit);
	std::cout << std::endl;
	exec_line("4 = 5 ?", exit);
	std::cout << std::endl;
}