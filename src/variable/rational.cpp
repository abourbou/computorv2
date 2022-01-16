#include "rational.hpp"

//coplien
rational::rational(std::string str) : Ivalue()
{
	size_t		idx;
	size_t		length = str.length();

	for	(auto it = str.end(); std::isspace(*it); --it)
		--length;
	if (length == 0)
		throw(std::runtime_error("empty string"));
	this->_value = std::stod(str, &idx);
	if (idx != length)
		throw(std::runtime_error("invalid caracters at the end"));
}

rational::rational(double value) : Ivalue()
{
	this->_value = value;
}

rational::~rational(void)
{
}

rational	&rational::operator=(const rational &rhs)
{
	this->_value = rhs._value;

	return(*this);
}

rational::rational(const rational &rhs) : Ivalue(rhs), _value(rhs._value)
{
}

//math operations
Ivalue	*rational::operator+(const Ivalue *rhs) const
{
	const rational	*r_other_var;

	if ((r_other_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value + r_other_var->_value));
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator-(const Ivalue *rhs) const
{
	const rational	*r_other_var;

	if ((r_other_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value - r_other_var->_value));
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator*(const Ivalue *rhs) const
{
	const rational	*r_other_var;

	if ((r_other_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value * r_other_var->_value));
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator/(const Ivalue *rhs) const
{
	const rational	*r_other_var;

	if ((r_other_var = dynamic_cast<const rational*>(rhs)))
	{
		if (r_other_var->_value == 0)
			throw(std::runtime_error("cannot divide by zero"));
		return(new rational(this->_value / r_other_var->_value));
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator%(const Ivalue *rhs) const
{
	const rational	*r_other_var;
	int				a;
	int				b;

	if ((r_other_var = dynamic_cast<const rational*>(rhs)))
	{
	if (!is_an_int(this->_value) || !is_an_int(r_other_var->_value))
			throw("modulo can be applied only with 2 integers");
		a = this->_value;
		b = r_other_var->_value;
		if (b == 0)
			throw("% 0 is undefined");
		return(new rational(a % b));
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

//convert the variable into a string
std::string	rational::to_string(void) const
{
	return(double_to_string(this->_value));
}

/* std::ostream	&operator<<(std::ostream &o, const rational &rhs)
{
	o << rhs.to_string();
	return (o);
} */