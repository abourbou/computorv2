
#include "math_function.hpp"
#include "Singleton.hpp"

//calcule the sin in degree
double	ft_sin(double nb)
{
	if (nb < 0)
		return (-1 * ft_sin(ft_abs(nb)));
	else if (nb >= 360)
	{
		int int_part = (int)nb;
		double decimal_part = nb - (double)int_part;
		int_part = int_part % 360;
		return(ft_sin((double)int_part + decimal_part));
	}
	else if (nb > 180)
	{
		if (nb > 270)
			return (-1 * ft_sin(360 - nb));
		return (-1 * ft_sin(nb - 180));
	}
	else if (nb > 90)
		return (ft_sin(180 - nb));
	else if (nb > 45)
		return (ft_cos(90 - nb));
	else if (nb == 45)
		return (0.7071067);
	else
	{
		nb = nb * PI / 180;
		double nb_sqr = nb * nb;
		double nb_quad = nb_sqr * nb_sqr;
		return (nb - nb*nb_sqr/6 + nb_quad*nb/120 - nb*nb_sqr*nb_quad/5040);
	}
	//developpement limité : x - x^3 / 6 + x ^ 5 / 120 - x ^7 / 5040
}

IValue	*fct_sin(const IValue *var)
{
	static Singleton *glob_var = Singleton::GetInstance();

	if (var->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational*>(var);
		double	value = r->get_value();
		if (glob_var->is_radian())
			value = value * RAD_TO_DEG;
		return (new Rational(ft_sin(value)));
	}
	else
		throw std::runtime_error("invalid type for sin");
}