#ifndef MATH_UTILITY_HPP
#define MATH_UTILITY_HPP

#include <iostream>

#ifndef PRECISION
# define PRECISION 5e-7
#endif

#define ft_abs(N) ((N < -1 * PRECISION)?(-N):(N))

bool		is_an_int(double number);
double		ft_sqrt(double number);
void		as_fraction(double number, int cycles = 10, double precision = PRECISION);
bool		is_zero(double number);
bool		is_greater(double number, double comparison);
bool		is_less(double number, double comparison);
bool		is_same(double number, double comparison);

#endif