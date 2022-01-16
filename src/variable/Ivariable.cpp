#include "Ivariable.hpp"

//basic
Ivariable::Ivariable(void){}
Ivariable::Ivariable(const Ivariable &rhs){(void)rhs;}
Ivariable::~Ivariable(void){}
Ivariable &Ivariable::operator=(const Ivariable &rhs){(void)rhs; return(*this);}

//operator

Ivariable *Ivariable::operator+(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

Ivariable *Ivariable::operator-(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

Ivariable *Ivariable::operator*(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

Ivariable *Ivariable::operator/(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

Ivariable *Ivariable::operator%(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

Ivariable *Ivariable::matrice_multiplication(const Ivariable *rhs) const
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}

std::ostream	&operator<<(std::ostream &o, const Ivariable &rhs)
{
	o << rhs.to_string();
	return(o);
}