#include "Ivalue.hpp"

//basic
Ivalue::Ivalue(bool is_constant): Ivariable("value", is_constant) {}
Ivalue::Ivalue(const Ivalue &rhs): Ivariable(rhs) {}
Ivalue::~Ivalue(void){}
Ivalue &Ivalue::operator=(const Ivalue &rhs)
{
	(void)rhs;
	if (this->_constant == true)
		throw(std::runtime_error("can not reassign a const variable"));
	return(*this);
}

//operator
Ivalue *Ivalue::operator+(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknown operation"));
}

Ivalue *Ivalue::operator-(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknown operation"));
}

Ivalue *Ivalue::operator*(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknown operation"));
}

Ivalue *Ivalue::operator/(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknown operation"));
}

Ivalue *Ivalue::operator%(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknown operation"));
}

Ivalue *Ivalue::matrice_multiplication(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
}

std::ostream	&operator<<(std::ostream &o, const Ivalue &rhs)
{
	o << rhs.to_string();
	return(o);
}