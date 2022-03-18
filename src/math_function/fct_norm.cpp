#include "math_function.hpp"

IValue	*fct_norm(const IValue *value)
{
	if (value->get_type() == variable_type::rational)
	{
		const Rational *r = static_cast<const Rational *>(value);
		return (new Rational(ft_abs(r->get_value())));
	}
	else if (value->get_type() == variable_type::complex)
	{
		const Complex *c = static_cast<const Complex *>(value);
		double real_c = c->get_realpart();
		double imag_c = c->get_imagpart();

		return (new Rational(ft_sqrt(real_c * real_c + imag_c * imag_c)));
	}
	else if (value->get_type() == variable_type::matrix)
	{
		const Matrix *m = static_cast<const Matrix *>(value);
		const std::vector<std::vector<double> > &arr = m->get_arr();
		double sum = 0;
		for (auto it_arr = arr.begin(); it_arr != arr.end(); ++it_arr)
			for (auto it_line = it_arr->begin(); it_line != it_arr->end(); ++it_line)
				sum += *it_line * *it_line;
		return (new Rational(ft_sqrt(sum)));
	}
	else
		throw std::runtime_error("invalid type for norm");
}