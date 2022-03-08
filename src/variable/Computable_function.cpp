
#include "Computable_function.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
Comput_fct::Comput_fct(std::string var, std::string expr) : IVariable(variable_type::function)
{
	//TODO
	(void)expr;
	_var = var;
	//_computation_expr = lexer(expr);
}

Comput_fct::Comput_fct(const Comput_fct &rhs): IVariable(rhs), _var(rhs._var),
					_computation_expr(rhs._computation_expr)
{}

Comput_fct	&Comput_fct::operator=(const Comput_fct &rhs)
{
	this->_var = rhs._var;
	this->_computation_expr = rhs._computation_expr;

	return(*this);
}

Comput_fct::~Comput_fct(void){}

IVariable *Comput_fct::clone(void) const
{
	return (new Comput_fct(*this));
}

std::string	Comput_fct::to_string(std::string str) const
{
	(void)str;
	//TODO
	return(_var);
}


void	Comput_fct::display(std::string var) const
{
	//TODO
	(void)var;
}

IValue	*Comput_fct::computation(const IValue *value) const
{
	//TODO
	(void)value;
	return(0);
}