
#include "Map_variable.hpp"
#include "Singleton.hpp"

bool test_map_variable(void)
{
	static Map_variable &map_test = Singleton::GetInstance()->get_map_variable();
	std::cout << std::endl << "********TEST MAP_VARIABLE********" << std::endl;
	map_test.show_map();
	std::cout << std::endl;

	std::cout << "add variables : " << std::endl;
	IVariable *y = new Complex(2, 5);
	size_t size_var[2] = {2, 3};
	IVariable *var1 = new Matrix(size_var, 5.5);
	map_test.add_var("y", y);
	map_test.add_var("var", var1);
	map_test.show_map();
	std::cout << std::endl;

	std::cout << "change variable y : " << std::endl;
	delete y;
	y = new Rational(-8);
	map_test.add_var("y", y);
	map_test.show_map();
	std::cout << std::endl;

	std::cout << "test change with caps : " << std::endl;
	delete y;
	y = new Complex(0,2);
	map_test.add_var("Y", y);
	map_test.show_map();
	std::cout << std::endl;

	std::cout << "try getting a variable : " << std::endl;
	const IVariable *y_copy = map_test.get_var("Y");
	std::cout << "y on map : " << y_copy->to_string() << std::endl;

	std::cout << "try add forbidden vars" << std::endl;
	try { map_test.add_var("EXIt", y); return false;}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl;}
	std::cout << std::endl;

	delete y;
	delete var1;
	return(true);
}