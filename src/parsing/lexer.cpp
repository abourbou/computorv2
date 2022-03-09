
#include "parsing.hpp"

///find first separator of the string at or after the position start
//return the pos of the separator or npos if not found
size_t		find_first_separator(std::string cmd, size_t start)
{
	size_t	end = cmd.find_first_of("+-*/%^(", start);

	if (end == std::string::npos || cmd[end] != '(')
		return(end);
	else
	{
		size_t nbr_parenth = 1;
		size_t i = end + 1;
		//std::cout << "str before : " << cmd.substr(i) << std::endl;
		while (nbr_parenth && i < cmd.length())
		{
			if (cmd[i] == '(')
				++nbr_parenth;
			else if (cmd[i] == ')')
				--nbr_parenth;
			++i;
		}
		//std::cout << "str after : " << cmd.substr(i) << std::endl;
		if (i >= cmd.length())
			return i;
		return (find_first_separator(cmd, i));
	}
}

//identify the type of value the str contain and transform it in pre_token
IToken	*tokenize_value(std::string token_str)
{
	if (token_str.empty())
		throw(std::runtime_error("empty Token is not recognizable"));
	if (token_str[0] == '(')
		return (new Token_parenth(token_str));
	else if (is_alpha(token_str))
		return (new Token_variable(token_str));
	else if (token_str.find('(') != std::string::npos || token_str.find(')') != std::string::npos)
		return (new Token_function(token_str));
	else
		return (new Token_value(token_str));
}

//parse the first value
//return the string containing the value and cmd become the rest
std::string lexer_first_value(std::string &cmd)
{
	size_t end;
	std::string pre_token_str;

	end = find_first_separator(cmd, 0);
	pre_token_str = cmd.substr(0, end);
	if (end < cmd.length())
		cmd = cmd.substr(end);
	else
		cmd = "";
	return (pre_token_str);
}

void	clean_lexer(std::list<IToken*> list_tok)
{
	for (auto it = list_tok.begin(); it != list_tok.end(); ++it)
		delete (*it);
}

//parse the first operator
//return the string containing the operator and cmd become the rest
std::string lexer_first_operator(std::string &cmd)
{
	size_t end;
	std::string pre_token_str;

	end = find_first_separator(cmd, 0);
	if (end)
		return (std::string());
	if (cmd[end] == '*' && cmd.length() > 1 && cmd[end + 1] == '*')
	{
		cmd = cmd.substr(2);
		return("**");
	}
	pre_token_str = cmd.substr(0, 1);
	cmd = cmd.substr(1);
	return(pre_token_str);
}

///transform the computation command into a list of pre_token
/// pre_tokens are operator, value or parenthesis
std::list<IToken*>	lexer(std::string cmd)
{
	std::list<IToken *>	my_list;
	std::string		token_str;

	while (!cmd.empty())
	{
		token_str = lexer_first_value(cmd);
		if (!token_str.empty())
		{
			try {my_list.push_back(tokenize_value(token_str));}
			catch (const std::exception& e)
			{
				clean_lexer(my_list);
				throw(std::runtime_error(e.what()));
			}
			//my_list.push_back(tokenize_value(token_str));

		}
		token_str = lexer_first_operator(cmd);
		if (!token_str.empty())
			my_list.push_back(new Token_operator(token_str));
	}
	return(my_list);
}
