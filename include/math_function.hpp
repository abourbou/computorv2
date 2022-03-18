#pragma once

#include "IValue.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "math_utility.hpp"

#define ft_abs(N) ((N<0)?-(N):(N))

double		ft_sqrt(double number);
IValue		*fct_sqrt(const IValue *value);
IValue		*fct_norm(const IValue *value);