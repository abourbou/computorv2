
#include "parsing.hpp"
#include "string_function.hpp"

void	print_list_token(std::list<IToken *> my_list)
{
	std::string array_type[] = {"math_operator", "variable", "math_function", "parenthesis", "value"};
	for (auto it = my_list.begin(); it != my_list.end(); ++it)
	{
		std::cout << "token : [" << (*it)->to_string() << "] of type : ";
		std::cout << array_type[static_cast<std::underlying_type<token_type>::type>((*it)->get_type())] << std::endl;
	}
}

void	test_token(std::string str)
{
	std::list<IToken *>	my_list;

	erase_white_space(str);
	std::cout << "test: {" + str + "}" << std::endl;
	try {
		my_list = lexer(str);
		print_list_token(my_list);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{ std::cout << "error: " << e.what() << std::endl;}
}

void	test_computation(void)
{
	std::list<pre_token>	my_list;

	//basic test
	test_token("5 + 3 * 2 % 6");
	test_token("2 * (5 + 2)");
	test_token("var * )5 * (2 + 5) + 2) * 3");
	test_token("-4 + 3");
	test_token("var * f(5.) - (2.5 + 5) + [[1.0]] * 3i^i");
	test_token("++--***/%");
	test_token("4dsfadf");
	test_token("[[4,]]");
	test_token("[[4]a[4]]");
	test_token("[[4]");
	test_token("i - a");
	test_token("f(0) + 5 * x");
	test_token("2*(x + 3*(x - 4))");
	test_token("(2*(x + 3*(x - 4)))");
}