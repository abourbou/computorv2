#include "IToken.hpp"
#include "Token_operator.hpp"
#include "Rational.hpp"

void	test_operation(std::string math_operator, IValue *v1, IValue *v2)
{
	auto tok1 = Token_operator(math_operator);
	IValue *result = tok1.operation(v1, v2);
	std::cout << "result of : " << v1->to_string() + " " + math_operator + " " + v2->to_string() << std::endl;
	result->display();
	std::cout << std::endl;
	delete result;
}

void	test_token(void)
{
	//test token_operator
	IValue *val1 = new Rational("9.0");
	IValue *val2 = new Rational("1.0");

	test_operation("+", val1, val2);
	test_operation("-", val1, val2);
	test_operation("*", val1, val2);
	test_operation("/", val1, val2);
	try {
		test_operation("**", val1, val2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete val1;
	delete val2;

	val1 = new Matrix("[[4, 2]]");
	val2 = new Matrix("[[2]; [1]]");
	//test_operation("+", val1, val2);
	//test_operation("-", val1, val2);
	test_operation("**", val1, val2);
	test_operation("**", val2, val1);

	delete val1;
	delete val2;
}