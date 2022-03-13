#include "Comput_fct.hpp"

void	unit_test_comput_fct(std::string var, std::string expr)
{
	std::cout << "test of : " << "f(" << var << ") : " << std::endl;
	erase_white_space(var);
	erase_white_space(expr);
	try {
		Comput_fct c(var, expr);
		std::cout << c.to_string() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_comput_fct(void)
{
	unit_test_comput_fct("x", "2 * 3 + x");
	unit_test_comput_fct("w", "5 * w - 2");
	unit_test_comput_fct("x", "x ^ 2 - 4 / 3 + 3 ** x");
	unit_test_comput_fct("y", " 43 * y / (4 % 2 * y)");
	unit_test_comput_fct("x", "2*(x + 3*(x - 4))");
	unit_test_comput_fct("x", "2 *x * i");
	unit_test_comput_fct("y", "y * 2 - var * i");
}

void	test_value(void)
{
	test_comput_fct();
}