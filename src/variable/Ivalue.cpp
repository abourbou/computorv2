#include "Ivalue.hpp"

//basic
Ivalue::Ivalue(void){}
Ivalue::Ivalue(const Ivalue &rhs){(void)rhs;}
Ivalue::~Ivalue(void){}
Ivalue &Ivalue::operator=(const Ivalue &rhs){(void)rhs; return(*this);}

//operator

Ivalue *Ivalue::operator+(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
}

Ivalue *Ivalue::operator-(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
}

Ivalue *Ivalue::operator*(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
}

Ivalue *Ivalue::operator/(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
}

Ivalue *Ivalue::operator%(const Ivalue *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("invalid operation"));
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