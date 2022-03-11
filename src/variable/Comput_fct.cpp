
#include "Comput_fct.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 * @param is_const		can the function change expression
 */
Comput_fct::Comput_fct(std::string var, std::string expr) : IFunction()
{
	_var = var;
	_expr = lexer(expr);
}

Comput_fct::Comput_fct(const Comput_fct &rhs): IFunction(), _var(rhs._var)
{
	for (auto it = rhs._expr.begin(); it != rhs._expr.end(); ++it)
		_expr.push_back((*it)->clone());
}

Comput_fct	&Comput_fct::operator=(const Comput_fct &rhs)
{
	this->_var = rhs._var;
	for (auto it = _expr.begin(); it != _expr.end(); ++it)
		delete *it;
	for (auto it = rhs._expr.begin(); it != rhs._expr.end(); ++it)
		_expr.push_back((*it)->clone());

	return(*this);
}

Comput_fct::~Comput_fct(void){
	for (auto it = _expr.begin(); it != _expr.end(); ++it)
		delete *it;
}

IVariable *Comput_fct::clone(void) const
{
	return (new Comput_fct(*this));
}

/**
 * @brief transform the function expression to string
 * @param str
 * @return std::string
 */
std::string	Comput_fct::to_string(void) const
{
	std::string	ret = "";
	//Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	for (auto it = _expr.begin(); it != _expr.end(); ++it)
	{
		if (it != _expr.begin())
			ret += " ";
		ret += (*it)->to_string();
	}
	return(ret);
}

void	Comput_fct::display(void) const
{
	std::cout << this->to_string() << std::endl;
}

IValue	*Comput_fct::computation(const IValue *value) const
{
	//TODO
	(void)value;
	return(0);
}