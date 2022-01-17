
#include "math_function.hpp"

//coplien
math_function::math_function(std::string expression, bool is_const) : Ivariable("function", is_const)
{
	//TODO
	(void)expression;
	_expression = 0;
	_variable = "";
	_str_expression = "";
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

	return(*this);
}

math_function::~math_function(void){}

std::string	math_function::to_string(std::string var)
{
	//TODO
	(void)var;
	return(_str_expression);
}

Ivalue	*math_function::computation(Ivalue *value)
{
	//TODO
	(void)value;
	return(0);
}