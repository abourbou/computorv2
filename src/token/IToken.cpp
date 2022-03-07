
#include "IToken.hpp"

IToken::IToken(std::string str, token_type type) : _lit(str), _type(type)
{
}

IToken::IToken(const IToken &rhs): _lit(rhs._lit), _type(rhs._type) {}

IToken::~IToken(void) {}