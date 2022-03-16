#pragma once

#include "IVariable.hpp"
#include "IValue.hpp"

class	IFunction: public IVariable
{
	protected:
		std::string	_var;

	public:
		IFunction(void);
		IFunction(const IFunction& rhs);
		IFunction& operator=(const IFunction& rhs);
		~IFunction();

		virtual const IValue	*fct_computation(const IValue *value) const = 0;
		std::string		get_var(void) const;
};