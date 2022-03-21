
#include <string>
#include <iostream>
#include "string_function.hpp"
#include "Singleton.hpp"
#include "IFunction.hpp"
#include "IVariable.hpp"

void	exec_get_var(std::string line)
{
	static Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	line = line.substr(0, line.size() - 2);
	if (is_alpha(line))
	{
		const IVariable *var = map.get_var(line);
		var->display();
	}
	else
	{
		size_t pos_parenth = line.find_first_of('(');
		size_t pos_end = line.find_first_of(')');
		if (pos_parenth == std::string::npos || pos_end != line.size() - 1
			|| pos_end - pos_parenth < 2)
			throw std::runtime_error("invalid syntax for function");

		std::string fct_str = line.substr(0, pos_parenth);
		std::string var = line.substr(pos_parenth + 1, pos_end - (pos_parenth + 1));
		
		const IVariable *value = map.get_var(fct_str);
		if (value->get_type() != variable_type::function)
			throw std::runtime_error(fct_str + " is not a function");
		const IFunction *fct = static_cast<const IFunction *>(map.get_var(fct_str));
		if (fct->get_var() != var)
			throw std::runtime_error("unvalid argument for the function");
		fct->display();
	}
}