#pragma once

#include <string>
#include <algorithm>
#include "IValue.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "math_utility.hpp"
#include "string_function.hpp"
#include "math_function.hpp"

class Matrix;

class Rational : public IValue
{
	private:
		//forbidden
		Rational(void);

	protected:
		//variable
		double	_value;

	public:
		//coplien
		Rational(std::string str);
		Rational(double value);
		Rational(const Rational &rhs);
		virtual ~Rational(void);
		Rational &operator=(const Rational &rhs);

		//getter - setter
		double	get_value(void) const;

		//math operations
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *operator/(const IValue *rhs) const;
		virtual IValue *operator%(const IValue *rhs) const;
		virtual IValue *operator^(const IValue *rhs) const;

		//methods to visualize the value
		IVariable			*clone(void) const;
		virtual std::string	to_string(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Rational &rhs);
