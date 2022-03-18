#pragma once

#include "IValue.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "math_utility.hpp"

#define ft_abs(N) ((N<0)?-(N):(N))
#define PI 3.141592
#define RAD_TO_DEG 57.2957795131 //360 / (2 * PI)

double		ft_sqrt(double number);
IValue		*fct_sqrt(const IValue *value);
IValue		*fct_norm(const IValue *value);

//trigo
double		ft_sin(double nb);
double		ft_cos(double nb);
double		ft_tan(double nb);
IValue		*fct_sin(const IValue *value);
IValue		*fct_cos(const IValue *value);
IValue		*fct_tan(const IValue *value);


//double		ft_pow(double);