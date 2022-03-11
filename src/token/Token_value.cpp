
#include "Token_value.hpp"

Token_value::Token_value(std::string str): IToken(str, token_type::value)
{
	Map_variable	&map_var = Singleton::GetInstance()->get_map_variable();

	if (is_alpha(str))
		_value = static_cast<IValue*>(map_var.get_var(str)->clone());
	else if (str.find('[') != std::string::npos || str.find(']') != std::string::npos)
		_value = new Matrix(str);
	else if (str.back() == 'i')
		_value = new Complex(str);
	else
		_value = new Rational(str);
}

Token_value::Token_value(const Token_value &rhs): IToken(rhs)
{
	_value = static_cast<IValue*>(rhs._value->clone());
}

Token_value &Token_value::operator=(const Token_value &rhs)
{
	delete _value;
	_value = static_cast<IValue*>(rhs._value->clone());

	return(*this);
}

Token_value::~Token_value(void)
{
	delete _value;
}

std::string Token_value::to_string(void) const
{
	return(_value->to_string());
}

const IValue *Token_value::get_value(void) const
{
	return(_value);
}

IToken	*Token_value::clone(void) const
{
	return(new Token_value(*this));
}