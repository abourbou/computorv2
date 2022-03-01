#pragma once
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "IVariable.hpp"
#include "IValue.hpp"

class Function: public IVariable
{
	typedef IValue *(function)(IValue *arg);

	private:
		//forbidden
		Function(void);

	protected:
		std::string	_var;
		std::string	_expr;
		function	*_f;

	public:
		//coplien
		Function(std::string var, std::string expression);
		Function(std::string var, std::string expresson, function f);
		Function(const Function &rhs);
		Function &operator=(const Function &rhs);
		virtual ~Function();

		//members
		std::string	to_string(void) const;
		IValue		*computation(IValue *value) const;
		virtual void	display(std::string var = "x") const;
};

#endif