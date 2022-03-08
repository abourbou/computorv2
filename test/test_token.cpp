#include "IToken.hpp"
#include "Token_operator.hpp"
#include "Token_variable.hpp"
#include "Token_function.hpp"
#include "Rational.hpp"
#include "singleton.hpp"
#include "Map_variable.hpp"
#include "Explic_fct.hpp"

void	test_operation(std::string math_operator, IValue *v1, IValue *v2)
{
	auto tok1 = Token_operator(math_operator);
	IValue *result = tok1.operation(v1, v2);
	std::cout << "result of : " << v1->to_string() + " " + math_operator + " " + v2->to_string() << std::endl;
	result->display();
	std::cout << std::endl;
	delete result;
}

void	test_operator(void)
{
	//test token_operator
	IValue *val1 = new Rational("9.0");
	IValue *val2 = new Rational("1.0");

	test_operation("+", val1, val2);
	test_operation("-", val1, val2);
	test_operation("*", val1, val2);
	test_operation("/", val1, val2);
	try { test_operation("**", val1, val2);}
	catch (const std::exception& e)
	{ std::cout << e.what() << std::endl;}

	delete val1;
	delete val2;

	val1 = new Matrix("[[4, 2]]");
	val2 = new Matrix("[[2]; [1]]");
	test_operation("**", val1, val2);
	test_operation("**", val2, val1);

	delete val1;
	delete val2;
}

void test_variable()
{
	Singleton *glob_var = Singleton::GetInstance();
	Map_variable	&map = glob_var->get_map_variable();

	Complex *var1 = new Complex(2, 3);

	map.add_var("compl", var1);

	Token_variable	tok1("compl");
	tok1.get_var()->display();

	try {
		Token_variable	tok2("unknown");
		tok2.get_var()->display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete var1;
}

IValue	*mult2(const IValue *var)
{
	Rational	two(2);

	return(two * var);
}

void	test_function()
{
	//TODO check if it works with a real function
	Map_variable &map = Singleton::GetInstance()->get_map_variable();
	Rational	r(2);
	Explic_fct	f("double", &mult2);
	IVariable *var;

	Token_function T1("F(4)");
	std::cout << "F(x) | " << T1.to_string() << std::endl;
	Token_function T2("F(4.0)");
	std::cout << "F(x) | " << T2.to_string() << std::endl;
	map.add_var("double", &f);

	Token_function tok("double(2)");
	var = tok.compute();
	std::cout << var->to_string() << std::endl;
	delete var;
	Token_function tok2("double(x)");
	try{var = tok2.compute();}catch(std::exception& e){std::cout << e.what() << std::endl;}
	Token_function tok3("unknown(3)");
	try{var = tok3.compute();}catch(std::exception& e){std::cout << e.what() << std::endl;}
}

void	test_token(void)
{
	//test_operator();
	//test_variable();
	test_function();
}