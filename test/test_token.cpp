#include "IToken.hpp"
#include "Token_operator.hpp"
#include "Token_variable.hpp"
#include "Token_function.hpp"
#include "Token_value.hpp"
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
	std::cout << "test invalid operation : ";
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
	std::cout << "must be (2 + 3i) : ";
	tok1.get_val()->display();
	std::cout << std::endl;

	try {
		std::cout << "test unknow variable on map : ";
		Token_variable	tok2("unknown");
		tok2.get_val()->display();
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
	Map_variable &map = Singleton::GetInstance()->get_map_variable();
	Rational	r(2);
	Explic_fct	f("double", &mult2);

	std::cout << "*******TEST TOKEN_FUNCTION********" << std::endl;


	map.add_var("two", &r);
	map.add_var("double", &f);
	Token_function tok("double(2)");

	std::cout << "double of 2 must be 4 : " << tok.to_string() << std::endl;
	Token_function tok_var("double(two)");
	std::cout << "double of the var two must be 4 : " << tok_var.to_string() << std::endl;

	std::cout << "test error var not defined : ";
	try{
		Token_function tok2("double(unknown)");
		std::cout << tok2.to_string() << std::endl;
	}
	catch(std::exception& e){std::cout << e.what() << std::endl;}
	std::cout << "test error function not defined : ";
	try{
		Token_function tok3("unknown(3)");
	}
	catch(std::exception& e){std::cout << e.what() << std::endl;}
}

void	test_a_value(std::string str)
{
	std::cout << "test value " + str + "" << std::endl;
	try{
		Token_value tk(str);
		tk.get_value()->display();
	}
	catch(const std::exception& e)
	{std::cout << "Unvalid value : " << e.what() << std::endl;}
	std::cout << "-------------" << std::endl;

}

void	test_token_value(void)
{
	std::cout << std::endl << "*******TEST TOKEN_VALUE********" << std::endl;
	test_a_value("4i");
	test_a_value("4.0x");
	test_a_value("-5.85987");
	test_a_value("[[5,8]]");
	test_a_value("[[-5.5877,+8994.]]");
	test_a_value("[[-5.5877,+8994.];[4.55, 0.0000000001]]");
}

void	test_token(void)
{
	std::cout << std::endl << "***********TEST TOKEN*********" << std::endl;
	test_operator();
	test_variable();
	test_function();
	test_token_value();
}