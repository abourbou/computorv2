
#include "math_function.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 * 
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
math_function::math_function(std::string var, std::string expr, bool is_const) : Ivariable("function", is_const)
{
	//TODO
	(void)var;
	(void)expr;
	_f = 0;
	_var = "";
	_expr = "";
}
/**
 * @brief Construct a new math function::math function object
 * with an already created function
 * 
 * @param var			string representing the var of the math function
 * @param expr			string representing the math function : "func(var)"
 * @param f				represent the math function
 * @param is_const		can the function change expression
 */
math_function::math_function(std::string var, std::string expr, function f, bool is_const): Ivariable("function", is_const),
																					_var(var), _expr(expr), _f(f)
{}

math_function::math_function(const math_function &rhs): Ivariable(rhs), _var(rhs._var),
					_expr(rhs._expr), _f(rhs._f)
{}

math_function	&math_function::operator=(const math_function &rhs)
{
	if (this->_const == true)
		throw(std::runtime_error("can not reassign a const variable"));
	this->_var = rhs._var;
	this->_expr = rhs._expr;
	this->_f = rhs._f;

	return(*this);
}

math_function::~math_function(void){}

std::string	math_function::to_string(void) const
{
	//TODO
	return(_expr);
}


std::string	math_function::to_string(std::string var) const
{
	//TODO
	(void)var;
	return(_expr);
}

Ivalue	*math_function::computation(Ivalue *value)
{
	//TODO
	(void)value;
	return(0);
}