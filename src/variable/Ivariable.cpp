#include "Ivariable.hpp"

//basic
Ivariable::Ivariable(std::string str){(void)str;}
Ivariable::Ivariable(const Ivariable &rhs){(void)rhs;}
Ivariable::~Ivariable(void){}
Ivariable &Ivariable::operator=(const Ivariable &rhs){(void)rhs; return(*this);}

//operator

Ivariable *Ivariable::operator+(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
Ivariable *Ivariable::operator-(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
Ivariable *Ivariable::operator*(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
Ivariable *Ivariable::operator/(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
Ivariable *Ivariable::operator%(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
Ivariable *Ivariable::matrice_multiplication(const Ivariable *rhs)
{
	(void)rhs;
	throw(std::runtime_error("unknow operation"));
}
