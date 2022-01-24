#ifndef RATIONAL_HPP
# define RATIONAL_HPP

#include <string>
#include <cmath>
#include <algorithm>
#include "Ivalue.hpp"
#include "complex.hpp"
#include "matrix.hpp"
#include "math_utility.hpp"
#include "string_function.hpp"

class matrix;

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
		rational(std::string str);
		rational(double value);
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