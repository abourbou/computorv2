
#include "IToken.hpp"

IToken::IToken(std::string str, token_type type) : _type(type), _lit(str)
{
}

IToken::IToken(const IToken &rhs): _type(rhs._type), _lit(rhs._lit) {}

IToken	&IToken::operator=(const IToken &rhs)
{
	_lit = rhs._lit;
	_type = rhs._type;

	return(*this);
}

IToken::~IToken(void) {}

token_type	IToken::get_type() const { return _type; }