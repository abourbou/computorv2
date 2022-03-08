#pragma once
#ifndef IVALUE_HPP
# define IVALUE_HPP

#include <string>
#include <stdexcept>
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
};

std::ostream	&operator<<(std::ostream &o, const IValue &rhs);

#endif