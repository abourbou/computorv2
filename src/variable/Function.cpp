
#include "Function.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
Function::Function(std::string var, std::string expr) : IVariable("function")
{
	//TODO
	(void)expr;
	_var = var;
	_explicit_fct = std::pair<std::string, function>("", nullptr);
	//_computation_expr = lexer(expr);
}

/**
 * @brief Construct a new math function::math function object
 * with an already created function
 *
 * @param expr			string representing the math function : "func(var)"
 * @param f				represent the math function
 */
Function::Function(std::string expr, function f): IVariable("function")
{
	_var = "x";
	_computation_expr = std::list<IToken *>();
	_explicit_fct = std::pair<std::string, function>(expr, f);
}

Function::Function(const Function &rhs): IVariable(rhs), _var(rhs._var),
					_computation_expr(rhs._computation_expr), _explicit_fct(rhs._explicit_fct)
{}

Function	&Function::operator=(const Function &rhs)
{
	this->_var = rhs._var;
	this->_computation_expr = rhs._computation_expr;
	this->_explicit_fct = rhs._explicit_fct;

	return(*this);
}

Function::~Function(void){}

IVariable *Function::clone(void) const
{
	return (new Function(*this));
}

std::string	Function::to_string(void) const
{
	//TODO
	return(_var);
}


void	Function::display(std::string var) const
{
	//TODO
	(void)var;
}

IValue	*Function::computation(IValue *value) const
{
	//TODO
	(void)value;
	return(0);
}