
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
	Map_variable	&map_var = Singleton::GetInstance()->get_map_variable();

	if (token_str.empty())
		throw(std::runtime_error("empty Token is not recognizable"));
	if (token_str[0] == '(')
		return (new Token_parenth(token_str));
	else if (is_alpha(token_str))
	{
		if (!map_var.is_var(token_str))
			return (new Token_variable(token_str));
		return(new Token_value(token_str));
	}
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

//check if their is 2 values or 2 operators in row
void	check_order_operator(const std::list<IToken*> &my_list)
{
	bool	last_is_op;
	bool	current_is_op;

	if (my_list.empty())
		throw(std::runtime_error("empty command"));
	for (auto it = my_list.begin(); it != my_list.end(); ++it)
	{
		current_is_op = (*it)->get_type() == token_type::math_operator;
		if (it != my_list.begin() && current_is_op == last_is_op)
			throw(std::runtime_error("unvalid syntax in lexer"));
		last_is_op = current_is_op;
	}
}

//check the case of the front token is an operator
//ex : -4 + 5 VALID -x + 8 UNVALID
//TODO handle -4 + 5 case
void	check_front_operator(std::list<IToken *> &my_list)
{
	auto it_first = my_list.begin();
	if ((*it_first)->get_type() == token_type::math_operator)
	{
		std::string str_operator = (*it_first)->to_string();
		auto it_second = ++my_list.begin();
		if (str_operator != "+" || str_operator != "-" || it_second == my_list.end())
			throw(std::runtime_error("unvalid syntax in lexer"));
		else if ((*it_second)->get_type() != token_type::value)
			throw(std::runtime_error("unvalid syntax in lexer"));
		//TODO check second token and change value
		// if (str_operator == '-')
		// {
		// 	it_second->
		// }
	}
}

///transform the computation command into a list of token
/// tokens are operator, value, variable, function or parenthesis
std::list<IToken*>	lexer(std::string cmd)
{
	std::list<IToken *>	my_list;
	std::string		token_str;

	try {
		while (!cmd.empty())
		{
			token_str = lexer_first_value(cmd);
			if (!token_str.empty())
				my_list.push_back(tokenize_value(token_str));
			token_str = lexer_first_operator(cmd);
			if (!token_str.empty())
				my_list.push_back(new Token_operator(token_str));
		}
		check_order_operator(my_list);
		check_front_operator(my_list);
	}
	catch (const std::exception& e)
	{
		clean_lexer(my_list);
		throw(std::runtime_error(e.what()));
	}
	return(my_list);
}
