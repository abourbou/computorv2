#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "singleton.hpp"
#include "string_function.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "Explic_fct.hpp"
#include "Comput_fct.hpp"

/**
 * @brief Token_function token with [fct(var / expr)]
 * var must be know
 */
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

		IValue	*compute(void) const;
		std::string	to_string(void) const;
		IToken	*clone(void) const;

};
