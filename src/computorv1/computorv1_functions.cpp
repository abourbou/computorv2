#include "computorv1_functions.hpp"

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
 * is an int or a float
 * return 0 if it is an int or 1 if it is a float
 */

bool	is_a_float(float number)
{
	int	convert = static_cast<int>(number);
	float	convert_float = static_cast<float>(convert);
	if (convert_float == number)
		return (0);
	return (1);

}


/**
 * *Absolute function
 */
float	ft_abs(float number)
{
	if (number < 0)
		return (-1 * number);
	return (number);
}

/**
 * Square root function
 * use the babylonian method
 * first part choose a good start number
 * second part apply the algorithm
 */

double ft_sqrt(double number)
{
	const double precision = 0.0000001;
	double buffer = 100;
	double puiss_100 = 0;
	double approximation = 7.00000000000;
	double last_approximation;
	int nbr_iteration = 1;

	if (number < 0)
	      throw std::domain_error("Can't calculate negative square");
	while (number > buffer)
	{
		buffer *= 100;
		++puiss_100;
	}
	for (int i = 0; i < puiss_100; ++i)
		approximation *= 10;

	//apply algorithm
	last_approximation = approximation;
	approximation = 0.5 * (last_approximation + number / last_approximation);

	while (ft_abs(approximation - last_approximation) > precision)
	{
		++nbr_iteration;
		last_approximation = approximation;
		approximation = 0.5 * (last_approximation + number / last_approximation);
	}
	return(approximation);
}

/**
 * @brief float_to_string
 * convert the float to a string in a correct format
 *
 * @param number @param precision
 * @return std::string number converted to string
 */
std::string	float_to_string(float number, int precision)
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