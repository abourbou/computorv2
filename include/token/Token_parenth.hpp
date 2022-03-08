#pragma once

#include <list>
#include "IToken.hpp"
#include "parsing.hpp"

class Token_parenth : public IToken
{
	private:
		std::list<IToken*>	_content;
	
	public:
		Token_parenth(void) = delete;
		Token_parenth(std::string str);
		Token_parenth(const Token_parenth &rhs) = delete;
		Token_parenth &operator=(const Token_parenth) = delete;
		virtual ~Token_parenth(void);

		//methods
		std::string	to_string(void) const;
		const std::list<IToken*>	&get_content(void) const;

};