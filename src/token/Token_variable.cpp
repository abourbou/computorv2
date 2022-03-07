
#include "Token_variable.hpp"
#include "parsing.hpp"
#include "singleton.hpp"
#include "Map_variable.hpp"

Token_variable::Token_variable(std::string str): IToken(str, token_type::variable)
{
}

Token_variable::Token_variable(const Token_variable &rhs): IToken(rhs) {}

Token_variable &Token_variable::operator=(const Token_variable &rhs)
{
	_type = rhs._type;
	_lit = rhs._lit;
	return(*this);
}

Token_variable::~Token_variable() {}

const IValue *Token_variable::get_var(void) const
{
	static Singleton *glob_var = Singleton::GetInstance();
	Map_variable &ref_map = glob_var->get_map_variable();
	const IValue	*value;

	value = dynamic_cast<const IValue*>(ref_map.get_var(_lit));
	if (!value)
		throw(std::runtime_error("error : var doesn't contain a value"));
	return(value);
}

std::string	Token_variable::get_lit(void) const
{
	return(_lit);
}