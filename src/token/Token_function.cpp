
#include "Token_function.hpp"

/**
 * @brief transform an string expression to a IValue
 *
 * @param expr
 * @return IValue* return 0 if no conversion is sutable
 */
IValue	*expr_to_value(std::string expr)
{
	if (is_alpha(expr))
		return(0);
	else if (expr.find('[') != std::string::npos || expr.find(']') != std::string::npos)
		return(new Matrix(expr));
	else if (expr.find('i') != std::string::npos)
		return(new Complex(expr));
	return (new Rational(expr));
}

/**
 * @brief Construct a token for a function
 *
 * @param str must be on the form [fct(var / expr)]
 */
Token_function::Token_function(std::string str): IToken(str, token_type::math_function)
{
	size_t start, end;

	start = str.find("(");
	if (start == std::string::npos || start == 0)
		throw std::runtime_error("unvalid function syntax");
	_fct = str.substr(0, start);
	end = str.find(")");
	if (end == std::string::npos || end <= start + 1 || end != str.size() - 1)
		throw std::runtime_error("unvalid function syntax");
	_expr = str.substr(start + 1, end - start - 1);
	_value = expr_to_value(_expr);
}

Token_function::Token_function(const Token_function &rhs): IToken(rhs), _fct(rhs._fct), _expr(rhs._expr)
{
	_value = (rhs._value) ? static_cast<IValue*>(rhs._value->clone()) : 0;
}

Token_function &Token_function::operator=(const Token_function &rhs)
{
	_fct = rhs._fct;
	_expr = rhs._expr;
	if (_value)
		delete _value;
	_value = (rhs._value) ? static_cast<IValue*>(rhs._value->clone()) : 0;
	return(*this);
}

Token_function::~Token_function()
{
	if (_value)
		delete _value;
}

const IValue *Token_function::compute(void) const
{
	Map_variable &map_var = Singleton::GetInstance()->get_map_variable();
	const IVariable *buffer_var;

	buffer_var = map_var.get_var(_fct);
	if (buffer_var->get_type() != variable_type::function)
		throw(std::runtime_error("the function isn't a function"));
	const Comput_fct *f = static_cast<const Comput_fct *>(buffer_var);
	const IValue *value = _value;
	if (!value)
	{
		buffer_var = map_var.get_var(_expr);
		if (buffer_var->get_type() == variable_type::function)
			throw(std::runtime_error("expression in the function must not be a function"));
		value = static_cast<const IValue*>(map_var.get_var(_expr));
	}
	return(f->computation(value));
}

std::string Token_function::to_string(void) const
{
	std::string expr = (_value) ? _value->to_string() : _expr;

	return(_fct + "(" + expr + ")");
}