
#include "Explic_fct.hpp"

Explic_fct::Explic_fct(std::string expr, function f): IFunction(), _expr(expr), _f(f)
{}

Explic_fct::Explic_fct(const Explic_fct &rhs): IFunction(), _expr(rhs._expr), _f(rhs._f)
{}

Explic_fct	&Explic_fct::operator=(const Explic_fct &rhs)
{
	_expr = rhs._expr;
	_f = rhs._f;

	return(*this);
}

Explic_fct::~Explic_fct(void)
{}

std::string	Explic_fct::to_string(void) const
{
	return(_expr + '(' + "x" + ')');
}

IVariable	*Explic_fct::clone(void) const
{
	return (new Explic_fct(*this));
}

const IValue	*Explic_fct::fct_computation(const IValue *value) const
{
	return(_f(value));
}

void	Explic_fct::display(void) const
{
	std::cout << this->to_string();
}