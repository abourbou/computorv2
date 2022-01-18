#ifndef COMPLEX_HPP
# define COMPLEX_HPP

#include "Ivalue.hpp"
#include "rational.hpp"
#include <string>

class complex : public Ivalue
{
	private:
		//forbidden
		complex(void);

	protected:
		//variable
		double	_real_part;
		double	_imag_part;

	public:
		//coplien
		complex(std::string str, bool is_const);
		complex(double real_part, double imag_part, bool is_const);
		complex(const complex &rhs);
		virtual ~complex(void);
		complex &operator=(const complex &rhs);

		//math operations
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;

		//convert the variable into a string
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const complex &rhs);


#endif