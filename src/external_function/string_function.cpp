
#include "string_function.hpp"

bool	is_whitespace(char c)
{
	static const std::string white_space = " \f\n\r\t\v";

	if (white_space.find(c) != white_space.npos)
		return (true);
	return (false);
}

/**
 * erase the white spaces
 * ex : "  a +  b= c+d  " => "a + b= c+d"
 */
void	erase_white_space(std::string &str_equation)
{
	auto end_iterator = std::remove_if(str_equation.begin(), str_equation.end(), is_whitespace);
	str_equation = std::string{str_equation.begin(), end_iterator};
}

/**
 * @brief double_to_string
 * convert the double to a string in a correct format
 *
 * @param number @param precision
 * @return std::string number converted to string
 */
std::string	double_to_string(double number, int precision)
{
	std::ostringstream ss;
	std::string buffer_number;

	ss << std::fixed << std::setprecision(precision) << number;
	buffer_number = ss.str();
	buffer_number = buffer_number.substr(0, buffer_number.find_last_not_of('0') + 1);
	if (buffer_number.back() == '.')
		buffer_number.pop_back();
	if (buffer_number.compare("-0") == 0)
		buffer_number = "0";
	return(buffer_number);
}

void	to_upper(std::string &str)
{
	for(auto it = str.begin(); it != str.end(); ++it)
		*it = toupper(*it);
}

bool	is_alpha(std::string str)
{
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (!isalpha(*it))
			return(false);
	}
	return (true);
}