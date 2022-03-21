#pragma once

#include "IValue.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "math_utility.hpp"

#define ft_abs(N) ((N<0)?-(N):(N))
#define PI 3.141592
#define RAD_TO_DEG 57.2957795131 //360 / (2 * PI)
#define INF (double)(1.0/0)
#define NINF (double)(-1.0/0)
#define E (double)2.7182818284590

double		ft_sqrt(double number);
IValue		*fct_sqrt(const IValue *value);
IValue		*fct_norm(const IValue *value);
IValue		*fct_abs(const IValue *value);

//trigo
double		ft_sin(double nb);
double		ft_cos(double nb);
double		ft_tan(double nb);
IValue		*fct_sin(const IValue *value);
IValue		*fct_cos(const IValue *value);
IValue		*fct_tan(const IValue *value);

//exp, log and pow
double		ft_exp(double nb); 
double		ft_ln(double nb);
double		ft_log(double nb);
IValue		*fct_exp(const IValue *value);
IValue		*fct_ln(const IValue *value);
IValue		*fct_log(const IValue *value);