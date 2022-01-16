#ifndef RATIONAL_HPP
# define RATIONAL_HPP

#include <string>
#include "Ivariable.hpp"
#include "computorv1_functions.hpp"
#include <cmath>

class rational : public Ivariable
{
	private:
		//forbidden
		rational(void);

		//variable
		double	_value;
		bool	_is_int;

	public:
	//coplien
		rational(std::string str);
		rational(double value);
		rational(const rational &rhs);
		virtual ~rational(void);
		rational &operator=(const rational &rhs);

	//math operations
		virtual Ivariable *operator+(const Ivariable *rhs) const;
		virtual Ivariable *operator-(const Ivariable *rhs) const;
		virtual Ivariable *operator*(const Ivariable *rhs) const;
		virtual Ivariable *operator/(const Ivariable *rhs) const;
		virtual Ivariable *operator%(const Ivariable *rhs) const;
	
	//convert the variable into a string
		virtual std::string	to_string(void) const;
};

//std::ostream	&operator<<(std::ostream &o, const rational &rhs);

#endif