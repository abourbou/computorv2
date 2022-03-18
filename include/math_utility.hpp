#pragma once

#include <iostream>

#ifndef PRECISION
# define PRECISION 5e-7
#endif

bool		is_an_int(double number);
bool		is_zero(double number);
bool		is_greater(double number, double comparison);
bool		is_less(double number, double comparison);
bool		is_same(double number, double comparison);
