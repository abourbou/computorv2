#pragma once

#include <list>
#include "IVariable.hpp"
#include "IValue.hpp"
#include "IToken.hpp"
#include "IFunction.hpp"
#include "parsing.hpp"

/**
 * @brief define a mathematical function with an list of token who can be computed
 */
class Comput_fct: public IFunction
{
	protected:
		std::string	_var;
		std::list<IToken *>	_expr;

	public:
		//coplien
		Comput_fct(void) = delete;
		Comput_fct(std::string var, std::string expr);
		Comput_fct(const Comput_fct &rhs);
		Comput_fct &operator=(const Comput_fct &rhs);
		virtual ~Comput_fct();

		//members
		std::string		to_string(std::string var = "") const;
		virtual IVariable	*clone(void) const;
		IValue			*computation(const IValue *value) const;
		virtual void		display(std::string var = "") const;
};
