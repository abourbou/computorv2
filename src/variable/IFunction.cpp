
#include "IFunction.hpp"

IFunction::IFunction(void) : IVariable(variable_type::function), _var("x")
{}

IFunction::IFunction(const IFunction &rhs) : IVariable(variable_type::function), _var(rhs._var)
{
	(void)rhs;
}

IFunction	&IFunction::operator=(const IFunction &rhs)
{
	_var = rhs._var;

	return(*this);
}

IFunction::~IFunction() {}

std::string	IFunction::get_var(void) const
{
	return (_var);
}