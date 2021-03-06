
#include "Token_operator.hpp"

Token_operator::Token_operator(std::string str): IToken(str, token_type::math_operator)
{
	if (!str.compare("+"))
		Operator_ptr = &IValue::operator+;
	else if (!str.compare("-"))
		Operator_ptr = &IValue::operator-;
	else if (!str.compare("*"))
		Operator_ptr = &IValue::operator*;
	else if (!str.compare("/"))
		Operator_ptr = &IValue::operator/;
	else if (!str.compare("%"))
		Operator_ptr = &IValue::operator%;
	else if (!str.compare("^"))
		Operator_ptr = &IValue::operator^;
	else if (!str.compare("**"))
		Operator_ptr = &IValue::Matrix_mult;
	else
		throw(std::runtime_error("unknown operator"));
}

Token_operator::Token_operator(const Token_operator &rhs): IToken(rhs), Operator_ptr(rhs.Operator_ptr)
{}

Token_operator::~Token_operator(void) {}

Token_operator &Token_operator::operator=(const Token_operator &rhs)
{
	_lit = rhs._lit;
	Operator_ptr = rhs.Operator_ptr;
	return(*this);
}

IValue *Token_operator::operation(const IValue *val1, const IValue *val2) const
{
	return (val1->*Operator_ptr)(val2);
}

std::string	Token_operator::to_string(void) const
{
	return (_lit);
}

IToken	*Token_operator::clone(void) const
{
	return(new Token_operator(*this));
}

const IValue	*Token_operator::get_value(void)
{
	throw(std::runtime_error("trying to access operator token value"));
}