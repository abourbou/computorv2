
#include "Token_parenth.hpp"

Token_parenth::Token_parenth(std::string str): IToken(str, token_type::parenthesis)
{
	if (str.length() < 3 || str.front() != '(' || str.back() != ')')
		throw std::runtime_error("syntax error parenthesis");
	std::string sstr = str.substr(1, str.length() - 2);
	_content = lexer(sstr);
}

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

Token_parenth::~Token_parenth()
{
	for (auto it = _content.begin(); it != _content.end(); ++it)
		delete *it;
}

const std::list<IToken *> &Token_parenth::get_content() const
{
	return (_content);
}