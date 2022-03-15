
#include "parsing.hpp"
#include "string_function.hpp"
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

	std::string expr1(line.begin(), it_equal);
	std::string expr2(++it_equal, line.end());

	if (expr1.empty() || expr2.empty())
		throw(std::runtime_error("empty expression"));
	else if (!is_alpha(expr1))
		throw(std::runtime_error("variable must only contain alphabetic characters"));

	std::list<IToken *> list_token = lexer(expr2);
	const IValue	*result = 0;
	try {
		result = computation(list_token);
		Map_variable	&map = Singleton::GetInstance()->get_map_variable();
		map.add_var(expr1, result);
	}
	catch (const std::exception& e)
	{
		clean_list_token(list_token);
		if (result)
			delete result;
		throw std::runtime_error(e.what());
	}
	clean_list_token(list_token);
	result->display();
	delete result;
}

/**
 * @brief execute the assignation of a function
 *
 * @param line
 */
void	exec_assign_fct(std::string line)
{
	auto it_equal = find(line.begin(), line.end(), '=');
	std::string name_fct, var_name;
	std::string expr1(line.begin(), it_equal);
	std::string expr2(++it_equal, line.end());


	size_t start = expr1.find("(");
	if (start == std::string::npos || start == 0)
		throw std::runtime_error("unvalid function syntax");
	name_fct = expr1.substr(0, start);

	size_t end = expr1.find(")");
	if (end == std::string::npos || end <= start + 1 || end != expr1.size() - 1)
		throw std::runtime_error("unvalid function syntax");
	var_name = expr1.substr(start + 1, end - start - 1);
	if (!is_alpha(var_name))
		throw std::runtime_error("unvalid function syntax");
	std::cout << "fct : [" << name_fct << "], var : [" << var_name << "], expr : [" << expr2 << "]" << std::endl;

	IVariable *new_fct = 0;
	try {
		new_fct = new Comput_fct(var_name, expr2);
		Map_variable	&map = Singleton::GetInstance()->get_map_variable();
		map.add_var(name_fct, new_fct);
		new_fct->display();
	}
	catch (const std::exception& e)
	{
		if (new_fct)
			delete new_fct;
		throw std::runtime_error(e.what());
	}
	delete new_fct;
}

/**
 * @brief execute a computation
 *
 * @param line
 */
void	exec_computation(std::string line)
{
	line = line.substr(0, line.size() - 2);
	//std::cout << "line computation : {" << line << "}" << std::endl;
	std::list<IToken *> list_tok = lexer(line);
	const IValue *result = 0;
	try {
		result = computation(list_tok);
		result->display();
	}
	catch (const std::exception& e)
	{
		if (result)
			delete result;
		clean_list_token(list_tok);
		throw std::runtime_error(e.what());
	}
	delete result;
	clean_list_token(list_tok);
}