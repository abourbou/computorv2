#pragma once

#include "IVariable.hpp"
#include "IValue.hpp"
#include "IToken.hpp"

/**
 * @brief function_computable class
 * @description define a mathematical function with at choice :
 * - an list of token who can be computed
 * - a function who take a value and return a value
 */
class Computable_function: public IVariable
{
	typedef IValue *(*function)(IValue *arg);

	protected:
		std::string	_var;
		std::list<IToken *>	_computation_expr;
		std::pair<std::string, function> _explicit_fct;

	public:
		//coplien
		Computable_function(void) = delete;
		Computable_function(std::string var, std::string expr);
		Computable_function(std::string expr, function f);
		Computable_function(const Computable_function &rhs);
		Computable_function &operator=(const Computable_function &rhs);
		virtual ~Computable_function();

		//members
		std::string			to_string(void) const;
		virtual IVariable	*clone(void) const;
		IValue			*computation(const IValue *value) const;
		virtual void		display(std::string var = "") const;
};
