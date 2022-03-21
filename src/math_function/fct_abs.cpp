#include "math_function.hpp"

IValue	*fct_abs(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational *>(value);
		return (new Rational(ft_abs(r->get_value())));
	}
	else
		throw std::runtime_error("invalid type for absolute value");
}