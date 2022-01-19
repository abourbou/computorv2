#ifndef MATH_UTILITY_HPP
#define MATH_UTILITY_HPP

#include <iostream>

#define ft_abs(N) ((N<0)?(-N):(N))

bool	is_an_int(double number);
double	ft_sqrt(double number);
void	as_fraction(double number, int cycles = 10, double precision = 5e-5);

#endif