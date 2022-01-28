#ifndef Complex_HPP
# define Complex_HPP

#include "IValue.hpp"
#include "Rational.hpp"
#include <string>

class Complex : public IValue
{
	private:
		//forbidden
		Complex(void);

	protected:
		//variable
		double	_real_part;
		double	_imag_part;

	public:
		//coplien
		Complex(std::string str);
		Complex(double real_part, double imag_part);
		Complex(const Complex &rhs);
		virtual ~Complex(void);
		Complex &operator=(const Complex &rhs);

		//math operations
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *operator/(const IValue *rhs) const;

		//members
		double			get_realpart(void) const;
		double			get_imagpart(void) const;
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Complex &rhs);


#endif