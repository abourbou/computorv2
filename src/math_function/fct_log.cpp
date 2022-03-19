#include "math_function.hpp"

double ft_log(double nb)
{
	//log(x) = ln(x) / ln(10)
	return (ft_ln(nb) * 0.4342944819); //1 / ln(10) = 0.4342944819
}

IValue	*fct_log(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational *>(value);
		double dvalue = r->get_value();
		if (dvalue <= 0)
			throw std::domain_error("log is not defined for this value");
		return (new Rational(ft_log(r->get_value())));
	}
	else
		throw std::runtime_error("invalid type for log function");
}