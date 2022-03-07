
#include "computation.hpp"

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

//identify the type of value the str contain and transform it in token
token	tokenize_value(std::string token_str)
{
	token_type	type;

	if (token_str.empty())
		throw(std::runtime_error("empty token is not recognizable"));
	if (token_str[0] == '(')
		type = token_type::parenthesis;
	else if (is_alpha(token_str))
		type = token_type::variable;
	else if (token_str.find('(') != std::string::npos || token_str.find(')') != std::string::npos)
		type = token_type::math_function;
	else if (token_str.find('[') != std::string::npos || token_str.find(']') != std::string::npos)
		type = token_type::matrix_value;
	else if (token_str.back() == 'i')
		type = token_type::complex_value;
	else
		type = token_type::rational_value;
	return(token(type, token_str));
}

//parse the first value
//return the string containing the value and cmd become the rest
std::string lexer_first_value(std::string &cmd)
{
	size_t end;
	std::string token_str;

	end = find_first_separator(cmd, 0);
	token_str = cmd.substr(0, end);
	if (end < cmd.length())
		cmd = cmd.substr(end);
	else
		cmd = "";
	return (token_str);
}


//parse the first operator
//return the string containing the operator and cmd become the rest
std::string lexer_first_operator(std::string &cmd)
{
	size_t end;
	std::string token_str;

	end = find_first_separator(cmd, 0);
	if (end)
		return (std::string());
	if (cmd[end] == '*' && cmd.length() > 1 && cmd[end + 1] == '*')
	{
		cmd = cmd.substr(2);
		return("**");
	}
	token_str = cmd.substr(0, 1);
	cmd = cmd.substr(1);
	return(token_str);
}

///transform the computation command into a list of token
/// tokens are operator, value or parenthesis
std::list<token>	lexer(std::string cmd)
{
	std::list<token>	my_list;
	std::string			token_str;
	token				token_buffer;

	while (!cmd.empty())
	{
		token_str = lexer_first_value(cmd);
		if (!token_str.empty())
			my_list.push_back(tokenize_value(token_str));
		token_str = lexer_first_operator(cmd);
		if (!token_str.empty())
			my_list.push_back(token(token_type::math_operator, token_str));
	}
	return(my_list);
}