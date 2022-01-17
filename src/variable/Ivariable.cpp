
#include "Ivariable.hpp"
/**
 * @brief Construct a new Ivariable:: Ivariable object
 * with the type of variable and if it is constant
 * @param type function or value
 * @param is_constant is the variable constant
 */

Ivariable::Ivariable(std::string type, bool is_constant) : _type(type), _constant(is_constant)
{
	if (this->_type.compare("function") && this->_type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

Ivariable::Ivariable(const Ivariable &rhs): _type(rhs._type), _constant(rhs._constant)
{
	if (this->_type.compare("function") && _type.compare("value"))
		throw(std::runtime_error("variable : invalid type"));
}

Ivariable::~Ivariable(void) {}

std::string	Ivariable::get_type(void) const
{
	return(_type);
}