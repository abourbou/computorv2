#pragma once

#include "IVariable.hpp"
#include "IValue.hpp"

class	IFunction: public IVariable
{
	public:
		IFunction(void);
		IFunction(const IFunction& rhs);
		IFunction& operator=(const IFunction& rhs);
		~IFunction();

		virtual const IValue	*fct_computation(const IValue *value) const = 0;
};