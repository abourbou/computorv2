#ifndef RATIONAL_HPP
# define RATIONAL_HPP

#include <string>
#include "Ivalue.hpp"
#include "computorv1_functions.hpp"
#include <cmath>

class rational : public Ivalue
{
	private:
		//forbidden
		rational(void);

		//variable
		double	_value;

	public:
		//coplien
		rational(std::string str, bool is_constant);
		rational(double value, bool is_constant);
		rational(const rational &rhs);
		virtual ~rational(void);
		rational &operator=(const rational &rhs);

		//math operations
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;
		virtual Ivalue *operator%(const Ivalue *rhs) const;

		//convert the variable into a string
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const rational &rhs);

#endif