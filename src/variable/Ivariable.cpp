
#include "Ivariable.hpp"
/**
 * @brief Construct a new Ivariable:: Ivariable object
 * with the type of variable and if it is const
 * @param type function or value
 * @param is_const is the variable const
 */

Ivariable::Ivariable(std::string type, bool is_const) : _type(type), _const(is_const)
{
	if (this->_type.compare("function") && this->_type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

Ivariable::Ivariable(const Ivariable &rhs): _type(rhs._type), _const(rhs._const)
{
	if (this->_type.compare("function") && _type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

Ivariable::~Ivariable(void) {}

std::string	Ivariable::get_type(void) const
{
	return(_type);
}