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

	protected:
		std::string _lit;
		token_type	_type;

	public:
		IToken(void) = delete;
		IToken &operator=(const IToken &rhs) = delete;
		IToken(std::string str, token_type type);
		IToken(const IToken &rhs);
		virtual ~IToken();

		//methods
		virtual std::string to_string() const = 0;
		token_type			get_type(void) const;
};
