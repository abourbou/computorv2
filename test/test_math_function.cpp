#include "math_function.hpp"
#include <cmath>

bool	compare_true_function(std::string name_fct, double d, double (*true_fct)(double), double (*my_fct)(double))
{
	double	true_f = true_fct(d);
	double	mine_f = my_fct(d);

	std::cout << "true :" << name_fct + '(' << d << ") : " << true_f << " | ";
	std::cout << "mine : " << name_fct + '(' << d << ") : " << mine_f << std::endl;
	return(true_f == mine_f);
}

void	unit_test_sqrt(double d)
{
	compare_true_function("sqrt", d, sqrt, ft_sqrt);

}

void test_sqrt(void)
{
	unit_test_sqrt(0);
	unit_test_sqrt(0.01);
	unit_test_sqrt(4);
	unit_test_sqrt(16);
	unit_test_sqrt(5929);
	unit_test_sqrt(238826116);
	unit_test_sqrt(274916.705625);
}

void test_math_function(void)
{
	//test_sqrt();
}