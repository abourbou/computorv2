
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
std::string	Comput_fct::to_string(std::string fct_var) const
{
	std::string	ret = "";
	Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	for (auto it = _expr.begin(); it != _expr.end(); ++it)
	{
		std::cout << "test in comput_fct : " << ret << std::endl;
		if (it != _expr.begin())
			ret += " ";
		if ((*it)->get_type() == token_type::variable)
		{
			std::string token_var = static_cast<Token_variable*>(*it)->get_name();
			if ( token_var == _var && !map.is_var(token_var))
				ret += !fct_var.empty() ? fct_var : _var;
			else
				ret += (*it)->to_string();
		}
		else if ((*it)->get_type() == token_type::parenthesis)
		{
			std::string str_content = (*it)->to_string();
			str_content = str_content.substr(1, str_content.length() - 2);
			erase_white_space(str_content);
			std::cout << "line parenth without parenth : " << str_content << std::endl;
			Comput_fct parenth_fct(_var, str_content);
			ret += parenth_fct.to_string(fct_var);
		}
		else
			ret += (*it)->to_string();
	}

	return(ret);
}


void	Comput_fct::display(std::string var) const
{
	std::cout << this->to_string(var) << std::endl;
}

IValue	*Comput_fct::computation(const IValue *value) const
{
	//TODO
	(void)value;
	return(0);
}