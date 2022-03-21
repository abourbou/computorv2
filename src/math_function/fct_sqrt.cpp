
#include "math_function.hpp"

/**
 * Square root function
 * use the babylonian method
 * first part choose a good start number
 * second part apply the algorithm
 */

double ft_sqrt(double number)
{
	const double precision = 0.00001;
	double buffer = 100;
	double puiss_100 = 0;
	double approximation = 7.0;
	double last_approximation;
	int nbr_iteration = 1;

	if (is_zero(number))
		return(0);
	if (is_less(number, 0))
	      throw std::domain_error("sqrt is not defined for negative values");
	while (number > buffer)
	{
		buffer *= 100;
		++puiss_100;
	}
	for (int i = 0; i < puiss_100; ++i)
		approximation *= 10;

	//apply algorithm
	last_approximation = approximation;
	approximation = 0.5 * (last_approximation + number / last_approximation);

	while (ft_abs(approximation - last_approximation) > precision)
	{
		++nbr_iteration;
		last_approximation = approximation;
		approximation = 0.5 * (last_approximation + number / last_approximation);
	}
	return(approximation);
}

IValue	*fct_sqrt(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational*>(value);
		return (new Rational(ft_sqrt(r->get_value())));
	}
	else
		throw std::runtime_error("invalid type for sqrt");
}
