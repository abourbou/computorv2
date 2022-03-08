
#include "Computable_function.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
Computable_function::Computable_function(std::string var, std::string expr) : IVariable(variable_type::function)
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
Computable_function::Computable_function(std::string expr, function f): IVariable(variable_type::function)
{
	_var = "x";
	_computation_expr = std::list<IToken *>();
	_explicit_fct = std::pair<std::string, function>(expr, f);
}

Computable_function::Computable_function(const Computable_function &rhs): IVariable(rhs), _var(rhs._var),
					_computation_expr(rhs._computation_expr), _explicit_fct(rhs._explicit_fct)
{}

Computable_function	&Computable_function::operator=(const Computable_function &rhs)
{
	this->_var = rhs._var;
	this->_computation_expr = rhs._computation_expr;
	this->_explicit_fct = rhs._explicit_fct;

	return(*this);
}

Computable_function::~Computable_function(void){}

IVariable *Computable_function::clone(void) const
{
	return (new Computable_function(*this));
}

std::string	Computable_function::to_string(void) const
{
	//TODO
	return(_var);
}


void	Computable_function::display(std::string var) const
{
	//TODO
	(void)var;
}

IValue	*Computable_function::computation(const IValue *value) const
{
	//TODO
	(void)value;
	return(0);
}