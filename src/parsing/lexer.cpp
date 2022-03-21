
#include "parsing.hpp"
#include "Rational.hpp"

///find first separator of the string at or after the position start
//return the pos of the separator or npos if not found
size_t		find_first_separator(std::string cmd, size_t start)
{
	size_t	end = cmd.find_first_of("+-*/%^([", start);

	if (cmd[end] == '(' || cmd[end] == '[')
	{
		char car_begin = cmd[end];
		char car_end = (car_begin == '(') ? ')' : ']';
		size_t diff = 1;
		size_t i = end + 1;

		while (diff && i < cmd.length())
		{
			if (cmd[i] == car_begin)
				++diff;
			else if (cmd[i] == car_end)
				--diff;
			++i;
		}
		if (i >= cmd.length())
			return i;
		return (find_first_separator(cmd, i));
	}
	else
		return(end);
}

//identify the type of value the str contain and transform it in pre_token
token_ptr	tokenize_value(std::string token_str)
{
	static Map_variable	&map_var = Singleton::GetInstance()->get_map_variable();

	if (token_str.empty())
		throw(std::runtime_error("empty token"));
	if (token_str[0] == '(')
		return (std::make_unique<Token_parenth>(Token_parenth(token_str)));
	else if (is_alpha(token_str))
	{
		if (!map_var.is_var(token_str))
			return (std::make_unique<Token_variable>(Token_variable(token_str)));
		return(std::make_unique<Token_value>(Token_value(token_str)));
	}
	else if (token_str.find('(') != std::string::npos || token_str.find(')') != std::string::npos)
		return (std::make_unique<Token_function>(Token_function(token_str)));
	else
		return (std::make_unique<Token_value>(Token_value(token_str)));
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

//check if their is 2 values or 2 operators in row
void	check_order_operator(const std::list<token_ptr> &my_list)
{
	bool	last_is_op;
	bool	current_is_op;

	if (my_list.empty())
		throw(std::runtime_error("empty command"));
	for (auto it = my_list.begin(); it != my_list.end(); ++it)
	{
		current_is_op = (*it)->get_type() == token_type::math_operator;
		if (it != my_list.begin() && current_is_op == last_is_op)
			throw(std::runtime_error("syntax error in lexer"));
		last_is_op = current_is_op;
	}
	if (last_is_op)
		throw(std::runtime_error("syntax error in lexer"));
}

//check the case of the front token is an operator
//ex : -4 + 5 VALID && -x + 8 UNVALID
void	check_front_operator(std::list<token_ptr> &my_list)
{
	auto it_first = my_list.begin();
	if ((*it_first)->get_type() == token_type::math_operator)
	{
		//check form ±value
		std::string str_operator = (*it_first)->to_string();
		auto it_second = ++my_list.begin();
		if ((str_operator != "+" && str_operator != "-") || it_second == my_list.end())
			throw(std::runtime_error("unvalid syntax in lexer"));
		else if ((*it_second)->get_type() != token_type::value)
			throw(std::runtime_error("unvalid syntax in lexer"));

		//if negatif, inverse the values
		if (str_operator == "-")
		{
			IValue *opposite = Rational(-1) * (*it_second)->get_value();
			*it_second = std::make_unique<Token_value>(Token_value(opposite)); //new Token_value(opposite);
		}
		//eliminate first operator
		my_list.pop_front();
	}
}

///transform the computation command into a list of token
/// tokens are operator, value, variable, function or parenthesis
void	lexer(std::string cmd, std::list<token_ptr> &token_list)
{
	std::string		token_str;

	while (!cmd.empty())
	{
		token_str = lexer_first_value(cmd);
		if (!token_str.empty())
			token_list.push_back(tokenize_value(token_str));
		token_str = lexer_first_operator(cmd);
		if (!token_str.empty())
			token_list.push_back(std::make_unique<Token_operator>(Token_operator(token_str)));
	}
	check_order_operator(token_list);
	check_front_operator(token_list);
}

