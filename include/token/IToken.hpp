#pragma once

#include <string>

enum class token_type
{
	math_operator,
	variable,
	math_function,
	parenthesis,
	value,
};

class	IToken {

	private:
		token_type	_type;

	protected:
		std::string	_lit;

	public:
		IToken(void) = delete;
		IToken(std::string str, token_type type);
		IToken(const IToken &rhs);
		IToken &operator=(const IToken &rhs);
		virtual ~IToken();

		//methods
		virtual std::string	to_string(void) const = 0;
		virtual IToken		*clone(void) const = 0;
		token_type		get_type(void) const;
};
