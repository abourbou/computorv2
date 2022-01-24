#include "rational.hpp"

//coplien
/**
 * @brief Construct a new rational::rational object
 *
 * @param str format accepted : [white space][+-][number][white space]
 * @param is_const is the variable const
 */
rational::rational(std::string str) : Ivalue()
{
	size_t		idx;
	int		sign = 1;
	size_t		length = str.length();

	for	(auto it = str.end(); std::isspace(*it); --it)
		--length;
	if (length == 0)
		throw(std::runtime_error("empty string"));
	idx = str.find_first_not_of(" \f\n\r\t\v");
	if (!isdigit(str[idx]) && str[idx] != '+' && str[idx] != '-')
		throw(std::runtime_error("invalid caracter at the beginning"));
	if(str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		++idx;
	}
	this->_value = std::stod(str, &idx);
	if (idx != length)
		throw(std::runtime_error("invalid caracter at the end"));
}

rational::rational(double value) : Ivalue(), _value(value)
{}

rational::~rational(void)
{}

rational	&rational::operator=(const rational &rhs)
{
	this->_value = rhs._value;

	return(*this);
}

rational::rational(const rational &rhs) : Ivalue(rhs), _value(rhs._value)
{
}

//getter - setter
double	rational::getvalue(void) const
{
	return(this->_value);
}

//math operations
Ivalue	*rational::operator+(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value + r_var->_value));
	else if ((c_var = dynamic_cast<const complex*>(rhs)))
		return(*c_var + this);
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator-(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value - r_var->_value));
	else if ((c_var = dynamic_cast<const complex *>(rhs)))
		return(new complex(this->_value - c_var->get_realpart(), c_var->get_imagpart()));
	else
		throw(std::runtime_error("invalid type for substraction"));
}

Ivalue	*rational::operator*(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	const matrix	*m_var;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
		return(new rational(this->_value * r_var->_value));
	else if((c_var = dynamic_cast<const complex*>(rhs)))
	{
		if (this->getvalue() == 0)
			return(new rational(0));
		return(new complex(this->_value * c_var->get_realpart(), this->_value * c_var->get_imagpart()));
	}
	else if ((m_var = dynamic_cast<const matrix*>(rhs)))
		return (*m_var * this);
	else
		throw(std::runtime_error("invalid type for multiplication"));
}

Ivalue	*rational::operator/(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	double		a;
	double		c;
	double		d;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		if (r_var->_value == 0)
			throw(std::runtime_error("cannot divide by zero"));
		return(new rational(this->_value / r_var->_value));
	}
	else if ((c_var = dynamic_cast<const complex*>(rhs)))
	{
		a = this->_value;
		c = c_var->get_realpart();
		d = c_var->get_imagpart();
		if (a == 0)
			return(new rational(0));
		return(new complex((a * c) / (c *c + d * d), ((- a * d) / (c *c + d * d))));
	}
	else
		throw(std::runtime_error("invalid type for division"));
}

Ivalue	*rational::operator%(const Ivalue *rhs) const
{
	const rational	*r_var;
	int				a;
	int				b;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
	if (!is_an_int(this->_value) || !is_an_int(r_var->_value))
			throw("modulo can be applied only with 2 integers");
		a = this->_value;
		b = r_var->_value;
		if (b == 0)
			throw("% 0 is undefined");
		return(new rational(a % b));
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*rational::operator^(const Ivalue *rhs) const
{
	const rational *r_var;
	float result = 1;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		if (!is_an_int(r_var->_value))
			throw(std::runtime_error("^ operation with float is not implemented yet"));
		else if (r_var->getvalue() < 0)
			throw(std::runtime_error("^ operation with negatives number is not implemented yet"));
		for(int i = r_var->_value; i > 0; --i)
			result *= this->_value;
		return(new rational(result));
	}
	else
		throw(std::runtime_error("invalid type for pow"));
}
//convert the variable into a string
std::string	rational::to_string(void) const
{
	return(double_to_string(this->_value));
}

std::ostream	&operator<<(std::ostream &o, const rational &rhs)
{
	o << rhs.to_string();
	return (o);
}