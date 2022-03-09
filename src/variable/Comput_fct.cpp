
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
 * if the var of the function is already a variable, take it as a variable
 * else print it with the name
 * @param str
 * @return std::string
 */
std::string	Comput_fct::to_string(std::string str) const
{
	Map_variable	&map = Singleton::GetInstance()->get_map_variable();
	std::string	ret = "";

	for (auto it = _expr.begin(); it != _expr.end(); ++it)
	{
		if (it != _expr.begin())
			ret += " ";
		if ((*it)->get_type() == token_type::variable)
		{
			std::string var = (*it)->to_string();
			ret += (map.is_var(var))
				? (*it)->to_string()
				: (str.empty()) ? _var
				: str;
			/*if (map.is_var(var))
				ret += (*it)->to_string();
			else
			{
				if (str.empty())
					ret += _var;
				else
					ret += str;
			}*/
		}
		else
			ret += (*it)->to_string();
	}

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