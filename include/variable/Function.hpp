#pragma once
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "IVariable.hpp"
#include "IValue.hpp"
#include "IToken.hpp"

/**
 * @brief function class
 * define a mathematical function with at choice :
 * - an list of token who can be computed
 * - a function who take a value and return a value
 */
class Function: public IVariable
{
	typedef IValue *(*function)(IValue *arg);

	protected:
		std::string	_var;
		std::list<IToken *>	_computation_expr;
		std::pair<std::string, function> _explicit_fct;

	public:
		//coplien
		Function(void) = delete;
		Function(std::string var, std::string expr);
		Function(std::string expr, function f);
		Function(const Function &rhs);
		Function &operator=(const Function &rhs);
		virtual ~Function();

		//members
		std::string			to_string(void) const;
		virtual IVariable	*clone(void) const;
		IValue				*computation(IValue *value) const;
		virtual void		display(std::string var = "") const;
};

#endif