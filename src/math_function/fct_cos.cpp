
#include "math_function.hpp"
#include "Singleton.hpp"

//calcule the cos in degree
double	ft_cos(double nb)
{
	if (nb < 0)
		return (ft_cos(-1 * nb));
	else if (nb >= 360)
	{
		int int_part = (int)nb;
		double decimal_part = nb - (double)int_part;
		int_part = int_part % 360;
		return(ft_cos((double)int_part + decimal_part));
	}
	else if (nb > 180)
	{
		if (nb > 270)
			return (ft_cos(360 - nb));
		return (-1 * ft_cos(nb - 180));
	}
	else if (nb > 90)
		return (-1 * ft_cos(180 - nb));
	else if (nb > 45)
		return (ft_sin(90 - nb));
	else if (nb == 45)
		return (0.7071067);
	else
	{
		nb = nb * PI / 180;
		double nb_sqr = nb * nb;
		double nb_quad = nb_sqr * nb_sqr;
		return (1 - nb_sqr / 2 + nb_quad / 24 - nb_sqr * nb_quad / 720);
	}
	//developpement limité 1 - x^2/2 + x^4/24 - x^6/720
}


IValue	*fct_cos(const IValue *var)
{
	static Singleton *glob_var = Singleton::GetInstance();

	if (var->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational*>(var);
		double	value = r->get_value();
		if (glob_var->is_radian())
			value = value * RAD_TO_DEG;
		return (new Rational(ft_cos(value)));
	}
	else
		throw std::runtime_error("invalid type for cos");
}
