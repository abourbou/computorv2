#pragma once

#include <list>
#include "IToken.hpp"
#include "parsing.hpp"

class Token_parenth : public IToken
{
	private:
		std::list<token_ptr>	_content;
		IValue *_buffer_result = 0;

	public:
		Token_parenth(void) = delete;
		Token_parenth(std::string str);
		Token_parenth(const Token_parenth &rhs);
		Token_parenth &operator=(const Token_parenth &rhs);
		virtual ~Token_parenth(void);

		//methods
		std::string	to_string(void) const;
		const std::list<token_ptr>	&get_content(void) const;
		IToken	*clone(void) const;
		const IValue	*get_value(void);
};