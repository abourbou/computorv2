#include "Rational.hpp"

//coplien
/**
 * @brief Construct a new Rational::Rational object
 *
 * @param str format accepted : [white space][+-][number][white space]
 * @param is_const is the variable const
 */
Rational::Rational(std::string str) : IValue()
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

Rational::Rational(double value) : IValue(), _value(value)
{}

Rational::~Rational(void)
{}

Rational	&Rational::operator=(const Rational &rhs)
{
	this->_value = rhs._value;

	return(*this);
}

Rational::Rational(const Rational &rhs) : IValue(rhs), _value(rhs._value)
{
}

//getter - setter
double	Rational::getvalue(void) const
{
	return(this->_value);
}

//math operations
IValue	*Rational::operator+(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
		return(new Rational(this->_value + r_var->_value));
	else if ((c_var = dynamic_cast<const Complex*>(rhs)))
		return(*c_var + this);
	else
		throw(std::runtime_error("invalid type for addition"));
}

IValue	*Rational::operator-(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
		return(new Rational(this->_value - r_var->_value));
	else if ((c_var = dynamic_cast<const Complex *>(rhs)))
		return(new Complex(this->_value - c_var->get_realpart(), c_var->get_imagpart()));
	else
		throw(std::runtime_error("invalid type for substraction"));
}

IValue	*Rational::operator*(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	const Matrix	*m_var;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
		return(new Rational(this->_value * r_var->_value));
	else if((c_var = dynamic_cast<const Complex*>(rhs)))
	{
		if (this->getvalue() == 0)
			return(new Rational(0));
		return(new Complex(this->_value * c_var->get_realpart(), this->_value * c_var->get_imagpart()));
	}
	else if ((m_var = dynamic_cast<const Matrix*>(rhs)))
		return (*m_var * this);
	else
		throw(std::runtime_error("invalid type for multiplication"));
}

IValue	*Rational::operator/(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	double		a;
	double		c;
	double		d;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		if (r_var->_value == 0)
			throw(std::runtime_error("cannot divide by zero"));
		return(new Rational(this->_value / r_var->_value));
	}
	else if ((c_var = dynamic_cast<const Complex*>(rhs)))
	{
		a = this->_value;
		c = c_var->get_realpart();
		d = c_var->get_imagpart();
		if (a == 0)
			return(new Rational(0));
		return(new Complex((a * c) / (c *c + d * d), ((- a * d) / (c *c + d * d))));
	}
	else
		throw(std::runtime_error("invalid type for division"));
}

IValue	*Rational::operator%(const IValue *rhs) const
{
	const Rational	*r_var;
	int				a;
	int				b;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
	if (!is_an_int(this->_value) || !is_an_int(r_var->_value))
			throw("modulo can be applied only with 2 integers");
		a = this->_value;
		b = r_var->_value;
		if (b == 0)
			throw("% 0 is undefined");
		return(new Rational(a % b));
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

IValue	*Rational::operator^(const IValue *rhs) const
{
	const Rational *r_var;
	float result = 1;

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		if (!is_an_int(r_var->_value))
			throw(std::runtime_error("^ operation with float is not implemented yet"));
		else if (r_var->getvalue() < 0)
			throw(std::runtime_error("^ operation with negatives number is not implemented yet"));
		for(int i = r_var->_value; i > 0; --i)
			result *= this->_value;
		return(new Rational(result));
	}
	else
		throw(std::runtime_error("invalid type for pow"));
}
//convert the variable into a string
std::string	Rational::to_string(void) const
{
	return(double_to_string(this->_value));
}

std::ostream	&operator<<(std::ostream &o, const Rational &rhs)
{
	o << rhs.to_string();
	return (o);
}