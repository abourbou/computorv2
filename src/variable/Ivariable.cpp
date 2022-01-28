
#include "IVariable.hpp"
/**
 * @brief Construct a new IVariable:: IVariable object
 * with the type of variable and if it is const
 * @param type function or value
 * @param is_const is the variable const
 */

IVariable::IVariable(std::string type) : _type(type)
{
	if (this->_type.compare("function") && this->_type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

IVariable::IVariable(const IVariable &rhs): _type(rhs._type)
{
	if (this->_type.compare("function") && _type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

IVariable::~IVariable(void) {}

std::string	IVariable::get_type(void) const
{
	return(_type);
}