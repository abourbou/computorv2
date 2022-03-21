#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include "IVariable.hpp"

class	IValue : public IVariable
{
	public:
		IValue(void) = delete;
		IValue(variable_type type);
		IValue(const IValue &rhs);
		IValue &operator=(const IValue &rhs);
		virtual ~IValue(void);

	//operator
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *operator/(const IValue *rhs) const;
		virtual IValue *operator%(const IValue *rhs) const;
		virtual IValue *operator^(const IValue *rhs) const;
		virtual IValue *Matrix_mult(const IValue *rhs) const;

	//methods
		virtual void		display(void) const;
};

std::ostream	&operator<<(std::ostream &o, const IValue &rhs);
