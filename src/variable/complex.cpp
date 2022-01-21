
#include "complex.hpp"

//coplien

/**
 * @brief Construct a new complex::complex object
 * with a string of the form : 5.0i
 * @param str format accepted : ([white space][+-][number])[white space])[i]([white space])
 * @param is_const
 */
complex::complex(std::string str, bool is_const) : Ivalue(is_const)
{
	size_t	pos;
	int	sign = 1;

	pos = str.find_first_not_of(" \f\n\r\t\v");
	if (str[pos] == '+' || str[pos] == '-')
		++pos;
	if (pos == std::string::npos || (!isdigit(str[pos]) && str[pos] != 'i'))
		throw(std::runtime_error("invalid string for complex creation"));
	this->_real_part = 0;
	this->_imag_part = 1 * sign;
	if (str[pos] != 'i')
		this->_imag_part = std::stod(str, &pos) * sign;
	pos = str.find_first_not_of(" \f\n\r\t\v", pos);
	if (pos == std::string::npos || str[pos] != 'i'
			|| str.find_first_not_of(" \f\n\r\t\v", pos + 1) != std::string::npos)
		throw(std::runtime_error("invalid string for complex creation"));
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create complex number with real value"));
}

complex::complex(double real_part, double imag_part, bool is_const) : Ivalue(is_const), _real_part(real_part), _imag_part(imag_part)
{
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create complex number with real value"));
}

complex::complex(const complex &rhs): Ivalue(rhs), _real_part(rhs._real_part), _imag_part(rhs._imag_part)
{
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create complex number with real value"));
}

complex::~complex(void){}

complex	&complex::operator=(const complex &rhs)
{
	if (this->_const == true)
		throw(std::runtime_error("can not reassign a const variable"));

	this->_real_part = rhs._real_part;
	this->_imag_part = rhs._imag_part;
	return(*this);
}

//math operations
Ivalue *complex::operator+(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	double			real_part;
	double			imag_part;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		real_part = this->_real_part + r_var->getvalue();
		imag_part = this->_imag_part;
	}
	else if ((c_var = dynamic_cast<const complex *>(rhs)))
	{
		real_part = this->_real_part + c_var->_real_part;
		imag_part = this->_imag_part + c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for addition"));
	if (imag_part == 0)
		return(new rational(real_part, false));
	return(new complex(real_part, imag_part, false));
}

Ivalue *complex::operator-(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	double			real_part;
	double			imag_part;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		real_part = this->_real_part - r_var->getvalue();
		imag_part = this->_imag_part;
	}
	else if ((c_var = dynamic_cast<const complex *>(rhs)))
	{
		real_part = this->_real_part - c_var->_real_part;
		imag_part = this->_imag_part - c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for subtraction"));
	if (imag_part == 0)
		return(new rational(real_part, false));
	return(new complex(real_part, imag_part, false));
}
Ivalue *complex::operator*(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	double			real_part;
	double			imag_part;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		real_part = this->_real_part * r_var->getvalue();
		imag_part = this->_imag_part * r_var->getvalue();
	}
	else if ((c_var = dynamic_cast<const complex *>(rhs)))
	{
		real_part = this->_real_part * c_var->_real_part - this->_imag_part * c_var->_imag_part;
		imag_part = this->_imag_part * c_var->_real_part + this->_real_part * c_var->_imag_part;
	}
	else
		throw(std::runtime_error("invalid type for multiplication"));
	if (imag_part == 0)
		return(new rational(real_part, false));
	return(new complex(real_part, imag_part, false));
}
Ivalue *complex::operator/(const Ivalue *rhs) const
{
	const rational	*r_var;
	const complex	*c_var;
	double			a,b,c,d;
	double			real_part;
	double			imag_part;

	if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		if (r_var->getvalue() == 0)
			throw("cannot divide by zero");
		real_part = this->_real_part / r_var->getvalue();
		imag_part = this->_imag_part / r_var->getvalue();
	}
	else if ((c_var = dynamic_cast<const complex *>(rhs)))
	{
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
		return(new rational(real_part, false));
	return(new complex(real_part, imag_part, false));
}

//members

double		complex::get_realpart(void) const
{
	return(this->_real_part);
}

double		complex::get_imagpart(void) const
{
	return(this->_imag_part);
}

std::string	complex::to_string(void) const
{
	std::string str = "";

	if (this->_real_part)
	{
		str += '(';
		str += double_to_string(this->_real_part);
		if (this->_imag_part > 0)
			str += " + ";
		else
			str += " - ";
		str += double_to_string(ft_abs(this->_imag_part));
		str += "i)";
	}
	else
	{
		str += double_to_string(this->_imag_part);
		str += "i";
	}

	return(str);
}

std::ostream	&operator<<(std::ostream &o, const complex &rhs)
{
	o << rhs.to_string();

	return (o);
}