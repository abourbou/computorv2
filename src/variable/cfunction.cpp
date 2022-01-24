
#include "cfunction.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
cfunction::cfunction(std::string var, std::string expr) : Ivariable("function")
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
cfunction::cfunction(std::string var, std::string expr, function f): Ivariable("function"),
																					_var(var), _expr(expr), _f(f)
{}

cfunction::cfunction(const cfunction &rhs): Ivariable(rhs), _var(rhs._var),
					_expr(rhs._expr), _f(rhs._f)
{}

cfunction	&cfunction::operator=(const cfunction &rhs)
{
	this->_var = rhs._var;
	this->_expr = rhs._expr;
	this->_f = rhs._f;

	return(*this);
}

cfunction::~cfunction(void){}

std::string	cfunction::to_string(void) const
{
	//TODO
	return(_expr);
}


std::string	cfunction::to_string(std::string var) const
{
	//TODO
	(void)var;
	return(_expr);
}

Ivalue	*cfunction::computation(Ivalue *value)
{
	//TODO
	(void)value;
	return(0);
}