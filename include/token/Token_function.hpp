#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "Singleton.hpp"
#include "string_function.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "Explic_fct.hpp"
#include "IFunction.hpp"

/**
 * @brief Token_function token with [fct(var / expr)]
 * var must be know
 */
class Token_function : public IToken
{
	private:
		const IValue		*_result;

	public:
		Token_function(void) = delete;
		Token_function(std::string str);
		Token_function(const Token_function &rhs);
		Token_function &operator=(const Token_function &rhs);
		virtual ~Token_function(void);

		std::string	to_string(void) const;
		IToken	*clone(void) const;
		const IValue	*get_value(void);
};
