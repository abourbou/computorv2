
#include <string>
#include <iostream>
#include <list>
#include "IToken.hpp"
#include "Polyn_equation.hpp"
#include "parsing.hpp"

std::string	transform_expr(std::string expr, std::string var)
{
	std::list<token_ptr>	buffer_list;
	std::string				new_expr;

	lexer(expr, buffer_list);
	for (auto it = buffer_list.begin(); it != buffer_list.end(); ++it)
	{
		if ((*it)->get_type() != token_type::variable)
			new_expr += (*it)->to_string();
		else
		{
			if (var.empty())
				var = (*it)->to_string();
			else
				if (var != (*it)->to_string())
					throw std::runtime_error("polynom in 2 variables");
			new_expr += "X";
		}
	}
	return (new_expr);
}

void	exec_polyn(std::string line)
{
	line.pop_back();
	size_t equal_pos = line.find("=");
	std::string expr1, expr2;
	std::string var_name;

	expr1 = line.substr(0, equal_pos);
	expr2 = line.substr(equal_pos + 1);
	expr1 = transform_expr(expr1, var_name);
	expr2 = transform_expr(expr2, var_name);

	Polyn_Equation polyn(expr1 + "=" + expr2);
}