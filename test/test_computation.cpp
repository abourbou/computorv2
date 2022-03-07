
#include "parsing.hpp"
#include "string_function.hpp"

void	print_list_token(std::list<pre_token> my_list)
{
	for (auto it = my_list.begin(); it != my_list.end(); ++it)
	{
		std::string array_type[] = {"operator", "var", "fct", "parenth", "rational", "compl", "matr"};
		std::cout << "pre_token : [" + it->second << "] of type : " << array_type[static_cast<size_t>(it->first)] << std::endl;
	}
}

void	test_token(std::string str)
{
	std::list<pre_token>	my_list;

	erase_white_space(str);
	std::cout << "test: {" + str + "}" << std::endl;
	my_list = lexer(str);
	print_list_token(my_list);
	std::cout << std::endl;
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
	test_token("");
}