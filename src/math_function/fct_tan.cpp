
#include "math_function.hpp"
#include "Singleton.hpp"

//calcule the tan in degree
double	ft_tan(double nb)
{
	double numerator = ft_sin(nb);
	double denominator = ft_cos(nb);

	return (numerator / denominator);
}

IValue	*fct_tan(const IValue *var)
{
	static Singleton *glob_var = Singleton::GetInstance();

	if (var->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational*>(var);
		double	value = r->get_value();
		if (glob_var->is_radian())
			value = value * RAD_TO_DEG;
		double result = ft_tan(value);
		if (result == INF || result == NINF)
			throw std::runtime_error("tan is not defined");
		return (new Rational(result));
	}
	else
		throw std::runtime_error("invalid type for tan");
}