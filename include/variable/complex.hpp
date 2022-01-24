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
		complex(std::string str);
		complex(double real_part, double imag_part);
		complex(const complex &rhs);
		virtual ~complex(void);
		complex &operator=(const complex &rhs);

		//math operations
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;

		//members
		double			get_realpart(void) const;
		double			get_imagpart(void) const;
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const complex &rhs);


#endif