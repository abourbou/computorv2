#ifndef cfunction_HPP
#define cfunction_HPP

#include "Ivariable.hpp"
#include "Ivalue.hpp"

class cfunction: public Ivariable
{
	typedef Ivalue *(function)(Ivalue *arg);

	private:
		//forbidden
		cfunction(void);

	protected:
		std::string	_var;
		std::string	_expr;
		function	*_f;

	public:
		//coplien
		cfunction(std::string var, std::string expression, bool is_const);
		cfunction(std::string var, std::string expresson, function f, bool is_const);
		cfunction(const cfunction &rhs);
		cfunction &operator=(const cfunction &rhs);
		virtual ~cfunction();

		//members
		std::string	to_string(void) const;
		std::string	to_string(std::string var) const;
		Ivalue		*computation(Ivalue *value);
};

#endif