#include "math_function.hpp"
#include <cmath>

void	compare_true_function(std::string name_fct, double d, double (*true_fct)(double), double (*my_fct)(double))
{
	double	true_f = true_fct(d);
	double	mine_f = my_fct(d);

	if (ft_abs((true_f - mine_f) / true_f) <= 0.000005)
	{
		std::cout << "OK" << std::endl;
		return ;
	}
	else if (true_f == 0 && ft_abs(mine_f) <= 0.000005)
	{
		std::cout << "OK" << std::endl;
		return ;
	}
	std::cout << "Error with " << name_fct <<"(" << d << ") fct, true(" << true_f << ") - mine(" << mine_f << ")" << std::endl;
}

void	unit_test_sqrt(double d) { compare_true_function("sqrt", d, sqrt, ft_sqrt);}

void test_sqrt(void)
{
	std::cout << "TEST SQRT " << std::endl;
	unit_test_sqrt(0);
	unit_test_sqrt(0.01);
	unit_test_sqrt(4);
	unit_test_sqrt(16);
	unit_test_sqrt(5929);
	unit_test_sqrt(238826116);
	unit_test_sqrt(274916.705625);
}

double	cos_deg(double nb)
{
	return (cos(nb * 2 * PI / 360));
}

void	unit_test_cos(double d) {compare_true_function("cos", d, cos_deg, ft_cos);}

void	test_cos(void)
{
	std::cout << "TEST COS " << std::endl;
	unit_test_cos(0);
	unit_test_cos(45);
	unit_test_cos(90);
	unit_test_cos(135);
	unit_test_cos(180);
	unit_test_cos(225);
	unit_test_cos(270);
	unit_test_cos(315);
	unit_test_cos(360);
	unit_test_cos(-45);
	unit_test_cos(10);
	unit_test_cos(15);
	unit_test_cos(20);
	unit_test_cos(25);
	unit_test_cos(30);
	unit_test_cos(35);
	unit_test_cos(40);
}

double	sin_deg(double nb)
{
	return (sin(nb * 2 * PI / 360));
}

void	unit_test_sin(double d) {compare_true_function("sin", d, sin_deg, ft_sin);}

void	test_sin(void)
{
	std::cout << "TEST SIN " << std::endl;
	unit_test_sin(0);
	unit_test_sin(45);
	unit_test_sin(90);
	unit_test_sin(135);
	unit_test_sin(180);
	unit_test_sin(225);
	unit_test_sin(270);
	unit_test_sin(315);
	unit_test_sin(360);
	unit_test_sin(-45);
	unit_test_sin(10);
	unit_test_sin(15);
	unit_test_sin(20);
	unit_test_sin(25);
	unit_test_sin(30);
	unit_test_sin(35);
	unit_test_sin(40);
}

double	tan_deg(double nb)
{
	return (tan(nb * 2 * PI / 360));
}

void	unit_test_tan(double d) {compare_true_function("tan", d, tan_deg, ft_tan);}

void	test_tan(void)
{
	std::cout << "TEST TAN " << std::endl;
	unit_test_tan(0);
	unit_test_tan(45);
	unit_test_tan(90);
	unit_test_tan(135);
	unit_test_tan(180);
	unit_test_tan(225);
	unit_test_tan(270);
	unit_test_tan(315);
	unit_test_tan(360);
	unit_test_tan(-45);
	unit_test_tan(10);
	unit_test_tan(15);
	unit_test_tan(20);
	unit_test_tan(25);
	unit_test_tan(30);
	unit_test_tan(35);
	unit_test_tan(40);
}

void	unit_test_exp(double d) {compare_true_function("exp", d, exp, ft_exp);}

void	test_exp(void)
{
	std::cout << "TEST EXP" << std::endl;
	unit_test_exp(0);
	unit_test_exp(1);
	unit_test_exp(2);
	unit_test_exp(10);
	unit_test_exp(10.25);
	unit_test_exp(10.5);
	unit_test_exp(10.75);
	unit_test_exp(15);
	unit_test_exp(20);
	unit_test_exp(25);
	unit_test_exp(-1);
	unit_test_exp(-2);
	unit_test_exp(-10);
	unit_test_exp(-20);
	unit_test_exp(-25);
}


void	unit_test_ln(double d) {compare_true_function("ln", d, log, ft_ln);}

void	test_ln(void)
{
	std::cout << "TEST LN" << std::endl;
	try {ft_ln(-10); std::cout << "ERROR : NO EXCEPTION FOR NEGATIF NUMBER" << std::endl;}
	catch (const std::exception& e){std::cout << "OK" << std::endl;}
	unit_test_ln(0.0000003);
	unit_test_ln(0.007);
	unit_test_ln(1);
	unit_test_ln(2);
	unit_test_ln(10);
	unit_test_ln(100);
	unit_test_ln(150);
	unit_test_ln(750);
	unit_test_ln(1000);
	unit_test_ln(20000);
	unit_test_ln(250000);
	unit_test_ln(500000);
	unit_test_ln(25000000);
}

void	unit_test_log(double d) {compare_true_function("log", d, log10, ft_log);}

void	test_log(void)
{
	std::cout << "TEST LOG" << std::endl;
	try {ft_log(-10); std::cout << "ERROR : NO EXCEPTION FOR NEGATIF NUMBER" << std::endl;}
	catch (const std::exception& e){std::cout << "OK" << std::endl;}
	unit_test_log(0.0000003);
	unit_test_log(0.007);
	unit_test_log(1);
	unit_test_log(2);
	unit_test_log(10);
	unit_test_log(100);
	unit_test_log(150);
	unit_test_log(750);
	unit_test_log(1000);
	unit_test_log(20000);
	unit_test_log(250000);
	unit_test_log(500000);
	unit_test_log(25000000);
}

void test_math_function(void)
{
	test_sqrt();
	test_cos();
	test_sin();
	test_tan();
	test_exp();
	test_ln();
	test_log();
}