
#include "Complex.hpp"

//coplien

/**
 * @brief Construct a new Complex::Complex object
 * with a string of the form : 5.0i
 * @param str format accepted : ([white space][+-][number])[white space])[i]([white space])
 * @param is_const
 */
Complex::Complex(std::string str) : IValue()
{
	size_t	pos;
	int	sign = 1;

	pos = str.find_first_not_of(" \f\n\r\t\v");
	if (str[pos] == '+' || str[pos] == '-')
		++pos;
	if (pos == std::string::npos || (!isdigit(str[pos]) && str[pos] != 'i'))
		throw(std::runtime_error("invalid string for Complex creation"));
	this->_real_part = 0;
	this->_imag_part = 1 * sign;
	if (str[pos] != 'i')
		this->_imag_part = std::stod(str, &pos) * sign;
	pos = str.find_first_not_of(" \f\n\r\t\v", pos);
	if (pos == std::string::npos || str[pos] != 'i'
			|| str.find_first_not_of(" \f\n\r\t\v", pos + 1) != std::string::npos)
		throw(std::runtime_error("invalid string for Complex creation"));
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create Complex number with real value"));
}

Complex::Complex(double real_part, double imag_part) : IValue(), _real_part(real_part), _imag_part(imag_part)
{
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create Complex number with real value"));
}

Complex::Complex(const Complex &rhs): IValue(rhs), _real_part(rhs._real_part), _imag_part(rhs._imag_part)
{
	if(_imag_part == 0)
		throw(std::runtime_error("trying to create Complex number with real value"));
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

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		real_part = this->_real_part + r_var->getvalue();
		imag_part = this->_imag_part;
	}
	else if ((c_var = dynamic_cast<const Complex *>(rhs)))
	{
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

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		real_part = this->_real_part - r_var->getvalue();
		imag_part = this->_imag_part;
	}
	else if ((c_var = dynamic_cast<const Complex *>(rhs)))
	{
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

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		real_part = this->_real_part * r_var->getvalue();
		imag_part = this->_imag_part * r_var->getvalue();
	}
	else if ((c_var = dynamic_cast<const Complex *>(rhs)))
	{
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

	if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		if (r_var->getvalue() == 0)
			throw("cannot divide by zero");
		real_part = this->_real_part / r_var->getvalue();
		imag_part = this->_imag_part / r_var->getvalue();
	}
	else if ((c_var = dynamic_cast<const Complex *>(rhs)))
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

std::string	Complex::to_string(void) const
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

void		Complex::display(std::string str) const
{
	(void)str;
	std::cout << this->to_string();
}


std::ostream	&operator<<(std::ostream &o, const Complex &rhs)
{
	o << rhs.to_string();

	return (o);
}