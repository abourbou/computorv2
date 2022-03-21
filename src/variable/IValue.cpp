#include "IValue.hpp"

//basic
IValue::IValue(variable_type type): IVariable(type) {}
IValue::IValue(const IValue &rhs): IVariable(rhs) {}
IValue::~IValue(void){}
IValue &IValue::operator=(const IValue &rhs)
{
	this->IVariable::operator=(rhs);
	return(*this);
}

//operator
IValue *IValue::operator+(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("+ is an invalid operation"));
}

IValue *IValue::operator-(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("- is an invalid operation"));
}

IValue *IValue::operator*(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("* is an invalid operation"));
}

IValue *IValue::operator/(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("/ is an invalid operation"));
}

IValue *IValue::operator%(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("% is an invalid operation"));
}

IValue *IValue::operator^(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("^ is an invalid operation"));
}

IValue *IValue::Matrix_mult(const IValue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("** is an invalid operation"));
}

void		IValue::display(void) const
{
	std::cout << BYellow << this->to_string() << Color_Off << std::endl;

}

std::ostream	&operator<<(std::ostream &o, const IValue &rhs)
{
	o << rhs.to_string();
	return(o);
}