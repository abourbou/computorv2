#include "math_function.hpp"

double	ft_ln(double nb)
{
	static double sqrt_10 = ft_sqrt(10);
	static double sqrt_sqrt_10 = ft_sqrt(sqrt_10);

	if (nb <= 0)
		throw std::domain_error("ln is not defined for this value");
	if (nb == 1)
		return 0;
	else if (nb >= 10 || nb < 1)
	{
		int	p = 0;
		while (nb >= 10)
		{
			nb = nb / 10;
			p++;
		}
		while (nb < 1)
		{
			nb = nb * 10;
			p--;
		}
		return (2.3025851 * p + ft_ln(nb)); //ln(10^p * nb) = p * ln(10) + ln(nb) = 2.3025851 * p + ln(nb)
	}
	else if (nb > sqrt_10)
		return (2 * ft_ln(ft_sqrt(nb))); // ln(x) = ln(sqrt(x)^2) = 2 * ln(sqrt(x))
	else if (nb > sqrt_sqrt_10)
		return (2 * ft_ln(ft_sqrt(nb))); // second time for better precision
	else
	{
		double y = (nb - 1) / (nb + 1);
		double y_3 = y * y * y;
		double y_4 = y_3 * y;
		return (2 * (y + y_3/3 + y_4*y/5 + y_4*y_3/7));
	}
}

IValue	*fct_ln(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational *>(value);
		return (new Rational(ft_ln(r->get_value())));
	}
	else
		throw std::runtime_error("invalid type for ln function");
}