
#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "singleton.hpp"

class Token_value : public IToken
{
	private:
		IValue *_value;

	public:
		Token_value(void) = delete;
		Token_value(std::string str);
		Token_value(const Token_value &rhs);
		Token_value &operator=(const Token_value &rhs_);
		virtual ~Token_value(void);

		//methods
		std::string to_string(void) const;
		IToken	*clone(void) const;
		const IValue *get_value(void) const;
};