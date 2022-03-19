#include "math_function.hpp"

//calcule e^pow
double	pow_exp(int pow)
{
	static double e = E;
	static double e_2 = e * e;
	static double e_4 = e_2 * e_2;
	static double e_8 = e_4 * e_4;
	static double e_16 = e_8 * e_8;
	bool is_neg = (pow < 0) ? true : false;
	double result = 1;

	pow = ft_abs(pow);
	while (pow > 0)
	{
		if (pow >= 16)
		{
			result *= e_16;
			pow -= 16;
		}
		if (pow >= 8)
		{
			result *= e_8;
			pow -= 8;
		}
		else if (pow >= 4)
		{
			result *= e_4;
			pow -= 4;
		}
		else if (pow >= 2)
		{
			result *= e_2;
			pow -= 2;
		}
		else
		{
			result *= e;
			pow -= 1;
		}
	}
	if (is_neg)
		result = 1 / result;
	return (result);
}

double	ft_exp(double nb)
{
	if (nb < -0.5 || nb > 0.5)
	{
		double int_part = (int)nb;
		if (nb - int_part > 0.5)
			int_part += 1;
		nb = nb - int_part;
		return (pow_exp(int_part) * ft_exp(nb));
	}
	else
	{
		double nb_sqr = nb * nb;
		double nb_quad = nb_sqr * nb_sqr;
		return (1 + nb + nb_sqr/2 + nb*nb_sqr/6 + nb_quad/24 + nb_quad*nb/120 + nb_quad*nb_sqr/720);
		//developpement limité : 1 + x + x^2 / 2! + x^3 / 3! + x^4 / 4! + x^5 / 5! + x^6 / 6!
	}
}

IValue *fct_exp(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational *>(value);
		return (new Rational(ft_exp(r->get_value())));
	}
	else
		throw std::runtime_error("invalid type for exp function");
}