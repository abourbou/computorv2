
#include "Token_variable.hpp"
#include "parsing.hpp"
#include "Singleton.hpp"
#include "Map_variable.hpp"

Token_variable::Token_variable(std::string str): IToken(str, token_type::variable)
{
}

Token_variable::Token_variable(const Token_variable &rhs): IToken(rhs) {}

Token_variable &Token_variable::operator=(const Token_variable &rhs)
{
	_lit = rhs._lit;
	return(*this);
}

Token_variable::~Token_variable() {}

std::string	Token_variable::to_string(void) const
{
	return(_lit);
}

IToken	*Token_variable::clone(void) const
{
	return(new Token_variable(*this));
}

const IValue *Token_variable::get_value(void)
{
	static Map_variable	&ref_map = Singleton::GetInstance()->get_map_variable();
	const IVariable	*buffer_variable;

	buffer_variable = ref_map.get_var(_lit);
	if (buffer_variable->get_type() == variable_type::function)
		throw(std::runtime_error("value is used as a function"));
	return(static_cast<const IValue *>(buffer_variable));
}