
#include "math_function.hpp"

math_function::math_function(std::string expression, bool is_const) : Ivariable("function", is_const)
{
	(void)expression;
}

math_function::math_function(math_function::function f, bool is_const): Ivariable("function", is_const), _expression(f)
{
}

math_function::math_function(const math_function &rhs): Ivariable(rhs), _variable(rhs._variable),
					_str_expression(rhs._str_expression), _expression(rhs._expression)
{}

math_function	&math_function::operator=(const math_function &rhs)
{
	if (this->_constant == true)
		throw(std::runtime_error("can not reassign a const variable"));
	this->_variable = rhs._variable;
	this->_str_expression = rhs._str_expression;
	this->_expression = rhs._expression;
}