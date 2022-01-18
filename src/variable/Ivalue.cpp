#include "Ivalue.hpp"

//basic
Ivalue::Ivalue(bool is_const): Ivariable("value", is_const) {}
Ivalue::Ivalue(const Ivalue &rhs): Ivariable(rhs) {}
Ivalue::~Ivalue(void){}
Ivalue &Ivalue::operator=(const Ivalue &rhs)
{
	(void)rhs;
	if (this->_const == true)
		throw(std::runtime_error("can not reassign a const variable"));
	else
		throw(std::runtime_error("= is invalid operation"));
	return(*this);
}

//operator
Ivalue *Ivalue::operator+(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("+ is invalid operation"));
}

Ivalue *Ivalue::operator-(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("- is invalid operation"));
}

Ivalue *Ivalue::operator*(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("* is invalid operation"));
}

Ivalue *Ivalue::operator/(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("/ is invalid operation"));
}

Ivalue *Ivalue::operator%(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("% is invalid operation"));
}

Ivalue *Ivalue::operator^(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("% is invalid operation"));
}

Ivalue *Ivalue::matrice_multiplication(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("** is invalid operation"));
}

std::ostream	&operator<<(std::ostream &o, const Ivalue &rhs)
{
	o << rhs.to_string();
	return(o);
}