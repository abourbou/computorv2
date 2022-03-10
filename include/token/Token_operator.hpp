#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"

class Token_operator : public IToken
{
	private:
		IValue	*(IValue::*Operator_ptr)(const IValue *rhs) const;

	public:
		Token_operator(void) = delete;
		Token_operator(std::string str);
		Token_operator(const Token_operator &rhs);
		Token_operator &operator=(const Token_operator &rhs);
		virtual ~Token_operator(void);

		//methods
		IValue *operation(const IValue *val1, const IValue *val2) const;
		std::string to_string(void) const;
		IToken	*clone(void) const;
};
