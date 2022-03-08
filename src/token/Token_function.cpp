
#include "Token_function.hpp"

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
	//TODO transform expr to value if it is not a variable
}

Token_function::Token_function(const Token_function &rhs): IToken(rhs), _fct(rhs._fct), _expr(rhs._expr)
{
	_value = (rhs._value) ? rhs._value.clone(); : 0;
}

Token_function &Token_function::operator=(const Token_function &rhs)
{
	_fct = rhs._fct;
	_expr = rhs._expr;
	if (_value)
		delete _value;
	_value = (rhs._value) ? rhs._value.clone(); : 0;
	return(*this);
}

Token_function::~Token_function(){}

const IValue *Token_function::get_fct(void) const
{
	//TODO if var call map_var and use it with the expr who will be transform first in value


	return(0);
}

std::string Token_function::get_lit(void) const
{
	return(_fct + "(" + _expr + ")");
}