#ifndef IVALUE_HPP
# define IVALUE_HPP

#include <string>
#include <stdexcept>
#include "IVariable.hpp"

class	IValue : public IVariable
{
	private:
	//coplien

	public:
		IValue(void);
		IValue(const IValue &rhs);
		virtual ~IValue(void);
		IValue &operator=(const IValue &rhs);

	//operator
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *operator/(const IValue *rhs) const;
		virtual IValue *operator%(const IValue *rhs) const;
		virtual IValue *operator^(const IValue *rhs) const;
		virtual IValue *Matrix_mult(const IValue *rhs) const;
};

std::ostream	&operator<<(std::ostream &o, const IValue &rhs);

#endif