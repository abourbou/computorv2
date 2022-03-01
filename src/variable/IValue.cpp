#include "IValue.hpp"

//basic
IValue::IValue(void): IVariable("value") {}
IValue::IValue(const IValue &rhs): IVariable(rhs) {}
IValue::~IValue(void){}
IValue &IValue::operator=(const IValue &rhs)
{
	(void)rhs;
	throw(std::runtime_error("= is invalid operation"));
	return(*this);
}

//operator
IValue *IValue::operator+(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("+ is invalid operation"));
}

IValue *IValue::operator-(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("- is invalid operation"));
}

IValue *IValue::operator*(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("* is invalid operation"));
}

IValue *IValue::operator/(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("/ is invalid operation"));
}

IValue *IValue::operator%(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("% is invalid operation"));
}

IValue *IValue::operator^(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("^ is invalid operation"));
}

IValue *IValue::Matrix_mult(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("** is invalid operation"));
}

std::ostream	&operator<<(std::ostream &o, const IValue &rhs)
{
	o << rhs.to_string();
	return(o);
}