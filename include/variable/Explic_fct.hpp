#pragma once

#include<iostream>
#include "IVariable.hpp"
#include "IValue.hpp"
#include "IToken.hpp"
#include "IFunction.hpp"

/**
 * @brief define a mathematical function describe by a programming function
 */
class Explic_fct: public IFunction
{
	typedef IValue *(*function)(const IValue *arg);

	protected:
		std::string	_expr;
		function	_f;

	public:
		//coplien
		Explic_fct(void) = delete;
		Explic_fct(std::string expr, function f);
		Explic_fct(const Explic_fct &rhs);
		Explic_fct &operator=(const Explic_fct &rhs);
		virtual ~Explic_fct();

		//members
		std::string		to_string(void) const;
		virtual IVariable	*clone(void) const;
		const IValue		*fct_computation(const IValue *value) const;
		virtual void		display(void) const;
};
