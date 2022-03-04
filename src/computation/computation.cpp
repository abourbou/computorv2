
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

//identify the type of data the str contain
block_type	identify_type_value(std::string str)
{
	if (str[0] == '(')
		return block_type::parenthesis;
	else
		return block_type::litteral_value;
}

///parse the computation command into a list of operator, value or parenthesis
std::list<block>	cmd_into_list(std::string cmd)
{
	size_t		i = 0;
	size_t		end;
	std::string	block_str;
	block		block_buffer;
	std::list<block> my_list;

	//particular case of first caracter is + or -
	if (cmd[0] == '+' || cmd[0] == '-')
	{
		end = find_first_separator(cmd, 1);
		block_str = cmd.substr(0, end);
		std::cout << "block_str : " + block_str << std::endl;
		block_buffer = block(identify_type_value(block_str), block_str);
		my_list.push_back(block_buffer);
		i = end + 1;
	}
	while (1)
	{
		end = find_first_separator(cmd, i);
		//std::cout << "separator at : " << end << std::endl;

		if (end == i)
			throw(std::runtime_error("two operators in a row"));
		else
			std::cout << "str : " << cmd.substr(i, end - i) << std::endl;
		if (end >= cmd.length())
			break;
		i = end + 1;
	}
	return(my_list);
}