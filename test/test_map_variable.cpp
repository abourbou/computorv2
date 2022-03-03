
#include "Map_variable.hpp"

bool test_map_variable(void)
{
	Map_variable map_test;
	std::cout << "test map_variable" << std::endl;
	map_test.show_map();

	std::cout << "add variables : " << std::endl;
	IVariable *y = new Complex(2, 5);
	size_t size_var[2] = {2, 3};
	IVariable *var1 = new Matrix(size_var, 5.5);
	map_test.add_var("y", y);
	map_test.add_var("var", var1);
	map_test.show_map();

	std::cout << "change variable y : " << std::endl;
	delete y;
	y = new Rational(-8);
	map_test.add_var("y", y);
	map_test.show_map();

	std::cout << "test change with caps : " << std::endl;
	delete y;
	y = new Complex(0,2);
	map_test.add_var("Y", y);
	map_test.show_map();

	std::cout << "try add forbidden var" << std::endl;
	try { map_test.add_var("EXIt", y);}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl;}
	try { map_test.add_var("history", y);}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl;}


	delete y;
	delete var1;
	return(true);
}