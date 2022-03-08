#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"
#include "singleton.hpp"
#include "string_function.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"

class Token_function : public IToken
{
	private:
		std::string	_fct;
		std::string	_expr;
		IValue		*_value;

	public:
		Token_function(void) = delete;
		Token_function(std::string str);
		Token_function(const Token_function &rhs);
		Token_function &operator=(const Token_function &rhs);
		virtual ~Token_function(void);

		const IValue	*compute(void) const;
		std::string	to_string(void) const;

};
