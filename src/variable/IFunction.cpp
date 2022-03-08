
#include "IFunction.hpp"

IFunction::IFunction(void) : IVariable(variable_type::function)
{}

IFunction::IFunction(const IFunction &rhs) : IVariable(variable_type::function)
{
	(void)rhs;
}

IFunction	&IFunction::operator=(const IFunction &rhs)
{
	(void)rhs;

	return(*this);
}

IFunction::~IFunction() {}