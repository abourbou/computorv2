#include "Rational.hpp"

//coplien
/**
 * @brief Construct a new Rational::Rational object
 *
 * @param str format accepted : [white space][+-][number][white space]
 * @param is_const is the variable const
 */
Rational::Rational(std::string str) : IValue(variable_type::rational)
{
	size_t		idx;
	int		sign = 1;
	size_t		length = str.length();

	for	(auto it = str.end(); std::isspace(*it); --it)
		--length;
	if (length == 0)
		throw(std::runtime_error("invalid rational"));
	idx = str.find_first_not_of(" \f\n\r\t\v");
	if (!isdigit(str[idx]) && str[idx] != '+' && str[idx] != '-')
		throw(std::runtime_error("invalid rational"));
	if(str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		++idx;
	}
	this->_value = std::stod(str, &idx);
	if (idx != length)
		throw(std::runtime_error("invalid rational"));
}

Rational::Rational(double value) : IValue(variable_type::rational), _value(value)
{}

Rational::Rational(const Rational &rhs) : IValue(rhs), _value(rhs._value)
{
}

Rational::~Rational(void)
{}

Rational	&Rational::operator=(const Rational &rhs)
{
	this->_value = rhs._value;

	return(*this);
}

//getter - setter
double	Rational::get_value(void) const
{
	return(this->_value);
}

//math operations
IValue	*Rational::operator+(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		return(new Rational(this->_value + r_var->_value));
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		return(*c_var + this);
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

IValue	*Rational::operator-(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		return(new Rational(this->_value - r_var->_value));
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		return(new Complex(this->_value - c_var->get_realpart(), -1 * c_var->get_imagpart()));
	}
	else
		throw(std::runtime_error("invalid type for substraction"));
}

IValue	*Rational::operator*(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	const Matrix	*m_var;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		return(new Rational(this->_value * r_var->_value));
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		return(*c_var * this);
	}
	else if (rhs->get_type() == variable_type::matrix)
	{
		m_var = static_cast<const Matrix*>(rhs);
		return (*m_var * this);
	}
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

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		if (r_var->_value == 0)
			throw(std::runtime_error("cannot divide by zero"));
		return(new Rational(this->_value / r_var->_value));
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex*>(rhs);
		a = this->_value;
		c = c_var->get_realpart();
		d = c_var->get_imagpart();
		if (a == 0 || d == 0)
			return(new Rational((a * c) / (c * c + d * d)));
		return(new Complex((a * c) / (c * c + d * d), ((- a * d) / (c *c + d * d))));
	}
	else
		throw(std::runtime_error("invalid type for division"));
}

IValue	*Rational::operator%(const IValue *rhs) const
{
	const Rational	*r_var;
	int				a;
	int				b;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		if (!is_an_int(this->_value) || !is_an_int(r_var->_value))
			throw("modulo can be applied only with 2 integers");
		a = this->_value;
		b = r_var->_value;
		if (b == 0)
			throw std::runtime_error("% 0 is undefined");
		return(new Rational(a % b));
	}
	else
		throw(std::runtime_error("invalid type for modulo"));
}

IValue	*Rational::operator^(const IValue *rhs) const
{
	const Rational *r_var;
	double result = 1;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		if (is_an_int(r_var->_value) && r_var->_value > 0)
		{
			for(int i = r_var->_value; i > 0; --i)
				result *= this->_value;
			return(new Rational(result));
		}
		else
			return (new Rational(ft_exp(r_var->_value * ft_ln(_value))));
	}
	else
		throw(std::runtime_error("invalid type for pow"));
}

IVariable		*Rational::clone(void) const
{
	return (new Rational(*this));
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