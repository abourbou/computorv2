
#include "computation.hpp"
#include "string_function.hpp"

bool	test_computation(void)
{
	//basic test
	std::string test1 = "5 + 3 * 2 % 6";
	erase_white_space(test1);
	std::cout << "test1: {" + test1 + "}" << std::endl;
	lexer(test1);
	std::cout << std::endl;

	//test parenth
	std::string test2 = "2 * (5 + 2)";
	erase_white_space(test2);
	std::cout << "test2: {" + test2 + "}" << std::endl;
	lexer(test2);
	std::cout << std::endl;

	//test parenth more complex
	std::string test3 = "var * )5 * (2 + 5) + 2) * 3";
	erase_white_space(test3);
	std::cout << "test3: {" + test3 + "}" << std::endl;
	lexer(test3);
	std::cout << std::endl;

	//test with + at the start
	std::string test4 = "-4 + 3";
	erase_white_space(test4);
	std::cout << "test4: {" + test4 + "}" << std::endl;
	lexer(test4);
	std::cout << std::endl;

	return(true);
}