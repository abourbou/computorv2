
#include "IVariable.hpp"
/**
 * @brief Construct a new IVariable:: IVariable object
 * with the type of variable and if it is const
 * @param type function or value
 * @param is_const is the variable const
 */

IVariable::IVariable(variable_type type) : _type(type)
{
}

IVariable::IVariable(const IVariable &rhs): _type(rhs._type)
{
}

IVariable	&IVariable::operator=(const IVariable &rhs)
{
	_type = rhs._type;

	return(*this);
}

IVariable::~IVariable(void) {}

variable_type	IVariable::get_type(void) const
{
	return(_type);
}