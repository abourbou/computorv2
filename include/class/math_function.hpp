#ifndef MATH_FUNCTION_HPP
#define MATH_FUNCTION_HPP

#include "Ivariable.hpp"
#include "Ivalue.hpp"

class math_function: public Ivariable
{
	typedef Ivalue *(function)(Ivalue *arg);

	private:
		//forbidden
		math_function(void);

	protected:
		std::string	_variable;
		std::string	_str_expression;
		function	*_expression;

	public:
		//coplien
		math_function(std::string expression, bool is_const);
		math_function(function f, bool is_const);
		math_function(const math_function &rhs);
		math_function &operator=(const math_function &rhs);
		virtual ~math_function();

		//members
		std::string	to_string(std::string var);
		Ivalue		*computation(Ivalue *value);
};

#endif