
#include <memory>
#include "parsing.hpp"
#include "Comput_fct.hpp"
#include "execution.hpp"

/**
 * @brief execute the assignation of a variable
 *
 * @param line
 */
void	exec_assign_var(std::string line)
{
	auto it_equal = find(line.begin(), line.end(), '=');
	static Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	std::string expr1(line.begin(), it_equal);
	std::string expr2(++it_equal, line.end());

	if (expr1.empty() || expr2.empty())
		throw(std::runtime_error("empty expression"));
	else if (!is_alpha(expr1))
		throw(std::runtime_error("variable must only contain alphabetic characters"));

	std::list<token_ptr> list_token;
	lexer_computation(expr2, list_token);
	std::shared_ptr<IValue>	result(computation(list_token));
	map.add_var(expr1, result.get());
	result->display();
}

/**
 * @brief execute the assignation of a function
 *
 * @param line
 */
void	exec_assign_fct(std::string line)
{
	static Map_variable	&map = Singleton::GetInstance()->get_map_variable();
	auto it_equal = find(line.begin(), line.end(), '=');
	std::string name_fct, var_name;
	std::string expr1(line.begin(), it_equal);
	std::string expr2(++it_equal, line.end());


	size_t start = expr1.find("(");
	if (start == std::string::npos || start == 0)
		throw std::runtime_error("unvalid function syntax");
	name_fct = expr1.substr(0, start);

	size_t end = expr1.find_last_of(")");
	if (end == std::string::npos || end <= start + 1 || end != expr1.size() - 1)
		throw std::runtime_error("unvalid function syntax");
	var_name = expr1.substr(start + 1, end - start - 1);
	if (!is_alpha(var_name))
		throw std::runtime_error("unvalid function syntax");

	std::shared_ptr<IVariable> new_fct(new Comput_fct(var_name, expr2));
	map.add_var(name_fct, new_fct.get());
	new_fct->display();
}
