
#include "parsing.hpp"
#include "execution.hpp"
#include "string_function.hpp"

void	print_list_token(std::list<token_ptr> &my_list)
{
	std::cout << "computation : {";
	for (auto it = my_list.begin(); it != my_list.end(); ++it)
	{
		if (it != my_list.begin())
			std::cout << " ";
		std::cout << (*it)->to_string();
	}
	std::cout << "}" << std::endl;
}

void	test_token(std::string str)
{
	std::list<token_ptr>	my_list;

	erase_white_space(str);
	std::cout << "test: {" + str + "}" << std::endl;
	try {
		lexer_computation(str, my_list);
		print_list_token(my_list);
		const IValue *buffer_value = computation(my_list);
		std::cout << "result : " << buffer_value->to_string() << std::endl;
		if (buffer_value)
			delete buffer_value;
	}
	catch(const std::exception& e)
	{ std::cout << "error: " << e.what() << std::endl;}
}

void	test_computation(void)
{
	//basic test
	test_token("5 + 3 * 2 / 6");
	std::cout << "must be 6" << std::endl << std::endl;

	test_token("-2 * (5 + 2)");
	std::cout << "must be -14" << std::endl << std::endl;

	test_token("x * 2 + 3");
	std::cout << std::endl;

	test_token("var * )5 * (2 + 5) + 2) * 3");
	std::cout << std::endl;

	test_token("-4i + 3 ^ 2 * 3");
	std::cout << "must be 27 - 4i" << std::endl;
	std::cout << std::endl;

	test_token("[[2]] * 3");
	std::cout << "must be [[6]]" << std::endl;
	std::cout << std::endl;

	test_token("-[[2]; [5]]");
	std::cout << std::endl;
	std::cout << "must be [[-2];[-5]]" << std::endl;

	test_token("var * f(5.) - (2.5 + 5) + [[1.0]] * 3i^i");
	std::cout << std::endl;

	test_token("++--***/%");
	std::cout << std::endl;

	test_token("4dsfadf");
	std::cout << std::endl;

	test_token("[[4,]]");
	std::cout << std::endl;

	test_token("[[4]a[4]]");
	std::cout << std::endl;

	test_token("[[4]");
	std::cout << std::endl;

	test_token("i - a");
	std::cout << std::endl;

	test_token("f(0) ^ 5 + x");
	std::cout << std::endl;

	test_token("2*(-1 + 3*(i - 4))");
	std::cout << "must be -26 + 6i" << std::endl;
	std::cout << std::endl;

	test_token("(2*(x + 3*(x - 4)))");
	std::cout << std::endl;

	test_token("0i * 5");
	std::cout << std::endl;

	test_token("4 - 3 - ( 2 * 3 ) ^ 2 *( 2 - 4 ) + 4");
	std::cout << "must be 77" << std::endl;
	std::cout << std::endl;
}