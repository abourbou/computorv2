#include "Comput_fct.hpp"

void	unit_test_comput_fct(std::string var, std::string expr)
{
	erase_white_space(var);
	erase_white_space(expr);
	Comput_fct c(var, expr);
	std::cout << "test f() : " << c.to_string() << std::endl;
	std::cout << "test f(x) : " << c.to_string("x") << std::endl;
	std::cout << "test f(y) : " << c.to_string("y") << std::endl;
	std::cout << std::endl;
}

void	test_comput_fct(void)
{
	//TODO test fct with a variable in it
	unit_test_comput_fct("x", "2 * 3 + x");
	unit_test_comput_fct("w", "5 * w - 2");
	unit_test_comput_fct("x", "x ^ 2 - 4 / 3 + 3 % x");
	unit_test_comput_fct("y", " 43 * y / (4 % 2 * y)");
	unit_test_comput_fct("x", "2*(x + 3*(x - 4))");
	unit_test_comput_fct("x", "2 *x * i");
}

void	test_value(void)
{
	test_comput_fct();
}