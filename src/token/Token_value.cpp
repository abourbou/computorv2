
#include "Token_value.hpp"

Token_value::Token_value(std::string str): IToken(str, token_type::value)
{
	Map_variable	&map_var = Singleton::GetInstance()->get_map_variable();

	if (is_alpha(str))
	{
		const IVariable	*var = map_var.get_var(str);
		if (var->get_type() == variable_type::function)
			throw std::runtime_error("cannot use a function as a value");
		_value = static_cast<IValue*>(var->clone());
	}
	else if (str.find('[') != std::string::npos || str.find(']') != std::string::npos)
		_value = new Matrix(str);
	else if (str.back() == 'i')
		_value = new Complex(str);
	else
		_value = new Rational(str);
	_lit = _value->to_string();
}

Token_value::Token_value(IValue *value): IToken(value->to_string(), token_type::value), _value(value)
{}

Token_value::Token_value(const Token_value &rhs): IToken(rhs)
{
	_value = static_cast<IValue*>(rhs._value->clone());
}

Token_value &Token_value::operator=(const Token_value &rhs)
{
	delete _value;
	_value = static_cast<IValue*>(rhs._value->clone());
	_lit = _value->to_string();

	return(*this);
}

Token_value::~Token_value(void)
{
	delete _value;
}

std::string Token_value::to_string(void) const
{
	return(_lit);
}

const IValue *Token_value::get_value(void)
{
	return(_value);
}

IToken	*Token_value::clone(void) const
{
	return(new Token_value(*this));
}