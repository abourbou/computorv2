#ifndef RATIONAL_HPP
# define RATIONAL_HPP

#include <string>
#include <cmath>
#include <algorithm>
#include "Ivalue.hpp"
#include "computorv1_functions.hpp"

#define ft_abs(N) ((N<0)?(-N):(N))

class rational : public Ivalue
{
	private:
		//forbidden
		rational(void);

	protected:
		//variable
		double	_value;

	public:
		//coplien
		rational(std::string str, bool is_const);
		rational(double value, bool is_const);
		rational(const rational &rhs);
		virtual ~rational(void);
		rational &operator=(const rational &rhs);

		//getter - setter
		double	getvalue(void) const;

		//math operations
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;
		virtual Ivalue *operator%(const Ivalue *rhs) const;
		virtual Ivalue *operator^(const Ivalue *rhs) const;

		//convert the variable into a string
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const rational &rhs);

#endif