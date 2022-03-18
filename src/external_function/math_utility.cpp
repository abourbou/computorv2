#include "math_utility.hpp"

/**
 * is an int or a double
 * return 1 if it is an int or 0 if it is a double
 */

bool	is_an_int(double number)
{
	return(((double)((int)number) == number));
}

bool	is_zero(double number)
{
	if (number < PRECISION && number > -1 * PRECISION)
		return(true);
	return(false);
}

bool	is_greater(double number, double comparison)
{
	if (number > comparison + PRECISION)
		return(true);
	return (false);
}

bool	is_less(double number, double comparison)
{
	if (number < comparison - PRECISION)
		return(true);
	return (false);
}

bool	is_same(double number, double comparison)
{
	if (is_zero(number - comparison))
		return(true);
	return (false);
}