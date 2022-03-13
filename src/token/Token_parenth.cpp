
#include "Token_parenth.hpp"

Token_parenth::Token_parenth(std::string str): IToken(str, token_type::parenthesis)
{
	if (str.length() < 3 || str.front() != '(' || str.back() != ')')
		throw std::runtime_error("syntax error parenthesis");
	std::string sstr = str.substr(1, str.length() - 2);
	_content = lexer(sstr);
}

Token_parenth::Token_parenth(const Token_parenth &rhs): IToken(rhs._lit, token_type::parenthesis)
{
	for (auto it = rhs._content.begin(); it != rhs._content.end(); ++it)
		_content.push_back((*it)->clone());
}

Token_parenth	&Token_parenth::operator=(const Token_parenth &rhs)
{
	for (auto it = _content.begin(); it != _content.end(); ++it)
		delete *it;
	for (auto it = rhs._content.begin(); it != rhs._content.end(); ++it)
		_content.push_back((*it)->clone());
	_lit = rhs._lit;

	return(*this);
}

Token_parenth::~Token_parenth()
{
	for (auto it = _content.begin(); it != _content.end(); ++it)
		delete *it;
}

//methods

std::string	Token_parenth::to_string(void) const
{
	std::string	ret = "(";

	for (auto it = _content.begin(); it != _content.end(); ++it)
	{
		if (it != _content.begin())
			ret += " ";
		ret += (*it)->to_string();
	}
	ret += ")";
	return (ret);
}

const std::list<IToken *> &Token_parenth::get_content() const
{
	return (_content);
}

IToken	*Token_parenth::clone(void) const
{
	return(new Token_parenth(*this));
}

const IValue	*Token_parenth::get_value(void) const
{
	//TODO computation
	return (0);
}