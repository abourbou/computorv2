
#include "Comput_fct.hpp"

//coplien

/**
 * @brief Construct a new math function::math function object
 *
 * @param var			variable in the expression
 * @param expr			string representing the function, will be interpreted by the computor ex: 4X^2 / (5 X)
 */
Comput_fct::Comput_fct(std::string var, std::string expr) : IFunction()
{
	_var = var;
	lexer(expr, _expr);

	for (const auto &token : _expr)
	{
		if (token->get_type() == token_type::variable && token->to_string() != _var)
			throw std::runtime_error("unknown variable");
	}
}

Comput_fct::Comput_fct(const Comput_fct &rhs): IFunction(rhs)
{
	for (const auto &token : rhs._expr)
		_expr.push_back(token_ptr(token->clone()));
}

Comput_fct	&Comput_fct::operator=(const Comput_fct &rhs)
{
	this->_var = rhs._var;
	_expr.clear();
	for (const auto &token : rhs._expr)
		_expr.push_back(token_ptr(token->clone()));

	return(*this);
}

Comput_fct::~Comput_fct(void){
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

	for (auto it = _expr.begin(); it != _expr.end(); ++it)
	{
		if (it != _expr.begin())
			ret += " ";
		if (_expr.size() > 1 && (*it)->get_type() == token_type::value
			&& (*it)->get_value()->get_type() == variable_type::complex)
		{
			const Complex *c = static_cast<const Complex *>((*it)->get_value());
			if (c->need_parenth())
				ret += "(";
			ret += (*it)->to_string();
			if (c->need_parenth())
				ret += ")";
		}
		else
			ret += (*it)->to_string();

	}
	return(ret);
}

const IValue	*Comput_fct::fct_computation(const IValue *value) const
{
	static Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	if (!map.is_var(_var))
	{
		map.add_var(_var, value);
		const IValue	*result = computation(_expr);
		map.remove_var(_var);
		return (result);
	}
	else
		return(computation(_expr));
}