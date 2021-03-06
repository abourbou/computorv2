
#include "Complex.hpp"

//coplien

/**
 * @brief Construct a new Complex::Complex object
 * with a string of the form : 5.0i
 * @param str format accepted : ([white space][+-][number])[white space])[i]([white space])
 * @param is_const
 */
Complex::Complex(std::string str) : IValue(variable_type::complex)
{
	size_t	pos;
	int	sign = 1;

	pos = str.find_first_not_of(" \f\n\r\t\v");
	if (str[pos] == '+' || str[pos] == '-')
		++pos;
	if (pos == std::string::npos || (!isdigit(str[pos]) && str[pos] != 'i'))
		throw(std::runtime_error("syntax error complex"));
	this->_real_part = 0;
	this->_imag_part = 1 * sign;
	if (str[pos] != 'i')
		this->_imag_part = std::stod(str, &pos) * sign;
	pos = str.find_first_not_of(" \f\n\r\t\v", pos);
	if (pos == std::string::npos || str[pos] != 'i'
		|| str.find_first_not_of(" \f\n\r\t\v", pos + 1) != std::string::npos)
		throw(std::runtime_error("syntax error complex"));
}

Complex::Complex(double real_part, double imag_part) : IValue(variable_type::complex), _real_part(real_part), _imag_part(imag_part)
{
}

Complex::Complex(const Complex &rhs): IValue(rhs), _real_part(rhs._real_part), _imag_part(rhs._imag_part)
{
}

Complex::~Complex(void){}

Complex	&Complex::operator=(const Complex &rhs)
{
	this->_real_part = rhs._real_part;
	this->_imag_part = rhs._imag_part;
	return(*this);
}

//math operations
IValue *Complex::operator+(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	double			real_part;
	double			imag_part;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		real_part = this->_real_part + r_var->get_value();
		imag_part = this->_imag_part;
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		real_part = this->_real_part + c_var->_real_part;
		imag_part = this->_imag_part + c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for addition"));
	if (imag_part == 0)
		return(new Rational(real_part));
	return(new Complex(real_part, imag_part));
}

IValue *Complex::operator-(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	double			real_part;
	double			imag_part;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		real_part = this->_real_part - r_var->get_value();
		imag_part = this->_imag_part;
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		real_part = this->_real_part - c_var->_real_part;
		imag_part = this->_imag_part - c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for subtraction"));
	if (imag_part == 0)
		return(new Rational(real_part));
	return(new Complex(real_part, imag_part));
}
IValue *Complex::operator*(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	double			real_part;
	double			imag_part;

	if (rhs->get_type() == variable_type::rational)
	{
		r_var = static_cast<const Rational*>(rhs);
		real_part = this->_real_part * r_var->get_value();
		imag_part = this->_imag_part * r_var->get_value();
	}
	else if (rhs->get_type() == variable_type::complex)
	{
		c_var = static_cast<const Complex *>(rhs);
		real_part = this->_real_part * c_var->_real_part - this->_imag_part * c_var->_imag_part;
		imag_part = this->_imag_part * c_var->_real_part + this->_real_part * c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for multiplication"));
	if (imag_part == 0)
		return(new Rational(real_part));
	return(new Complex(real_part, imag_part));
}

IValue *Complex::operator/(const IValue *rhs) const
{
	const Rational	*r_var;
	const Complex	*c_var;
	double			a,b,c,d;
	double			real_part;
	double			imag_part;

	if (rhs->get_type() == variable_type::complex)
	{
		r_var = static_cast<const Rational*>(rhs);
		if (r_var->get_value() == 0)
			throw std::runtime_error("cannot divide by zero");
		real_part = this->_real_part / r_var->get_value();
		imag_part = this->_imag_part / r_var->get_value();
	}
	else if (rhs->get_type() == variable_type::rational)
	{
		c_var = static_cast<const Complex *>(rhs);
		a = this->_real_part;
		b = this->_imag_part;
		c = c_var->_real_part;
		d = c_var->_imag_part;
		real_part = (a * c + b * d) / (c *c + d * d);
		imag_part = ((b * c - a * d) / (c *c + d * d));
	}
	else
		throw(std::runtime_error("invalid type for divison"));
	if (imag_part == 0)
		return(new Rational(real_part));
	return(new Complex(real_part, imag_part));
}

//members

double		Complex::get_realpart(void) const
{
	return(this->_real_part);
}

double		Complex::get_imagpart(void) const
{
	return(this->_imag_part);
}

bool		Complex::need_parenth(void) const
{
	if (_real_part != 0 && _imag_part != 0)
		return true;
	return false;
}

IVariable *Complex::clone(void) const
{
	return (new Complex(*this));
}

std::string	Complex::to_string(void) const
{
	std::string str;

	if (this->_real_part && this->_imag_part)
	{
		str += double_to_string(this->_real_part);
		if (this->_imag_part)
		{
			if (this->_imag_part > 0)
				str += " + ";
			else
				str += " - ";
			if (this->_imag_part != 1)
				str += double_to_string(ft_abs(this->_imag_part));
			str += "i";
		}
	}
	else
	{
		if (this->_imag_part != 1)
			str += double_to_string(this->_imag_part);
		if (this->_imag_part != 0)
			str += "i";
	}

	return(str);
}

std::ostream	&operator<<(std::ostream &o, const Complex &rhs)
{
	o << rhs.to_string();

	return (o);
}