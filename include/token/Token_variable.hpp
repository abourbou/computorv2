#pragma once

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"
#include "Singleton.hpp"

class Token_variable : public IToken
{
	private:
		Token_variable(void);

	public:
		Token_variable(std::string str);
		Token_variable(const Token_variable &rhs);
		Token_variable &operator=(const Token_variable &rhs);
		virtual ~Token_variable(void);

		//methods
		std::string		to_string(void) const;
		IToken		*clone(void) const;
		const IValue	*get_value(void) const;
};
