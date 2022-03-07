
#include "parsing.hpp"
#include "string_function.hpp"

void	exec_assign_value(std::string line)
{
	auto it_equal = find(line.begin(), line.end(), '=');


	std::string expr1(line.begin(), it_equal);
	std::string expr2(++it_equal, line.end());

	std::cout << "expr1 : [" << expr1 << "], expr2 : [" << expr2 << "]" << std::endl;

	if (expr1.empty() || expr2.empty())
		throw(std::runtime_error("empty expression"));
	else if (!is_alpha(expr1))
		throw(std::runtime_error("variable must only contain alphabetic characters"));

}