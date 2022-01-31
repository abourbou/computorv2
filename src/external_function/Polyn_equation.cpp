
#include "Polyn_equation.hpp"


/**
 * check if this is a valid equation (one and only one equal sign)
 * put each side of the equation on a map
 * reduce the polynom and put the degree
 * solve it
 */
Polyn_Equation::Polyn_Equation(std::string str_equation)
{
	erase_white_space(str_equation);
	size_t position_equal = is_an_equation(str_equation);
	if (position_equal == 0)
		throw InvalidSide(0, "empty side");
	else if (position_equal ==str_equation.length() - 1)
		throw InvalidSide(1, "empty side");
	parse_side(false, str_equation.substr(0, position_equal));
	parse_side(true, str_equation.substr(position_equal + 1));
	reduce_it();
	std::cout << UWhite "Reduced form:" << Green << this->convert_string() << Color_Off << std::endl;
	std::cout << UWhite "Polynomial degree:" << Green << " " << max_degree << Color_Off << std::endl;
	solve_it();
}

Polyn_Equation::~Polyn_Equation(void)
{
}

/**
 * convert the equation to a string
 */

std::string	Polyn_Equation::convert_string(void) const
{
	std::string s_equation;
	auto side = _left_side;
	auto iterator = side.begin();

	//left side
	for (; iterator != side.end(); ++iterator)
	{
		s_equation += " ";
		if (iterator != side.begin())
		{
			if (is_greater(iterator->second, 0) || is_zero(iterator->second))
				s_equation += "+ ";
			else
			{
				s_equation += "- ";
				iterator->second *= -1;
			}
		}
		if (iterator->first == 0)
			s_equation += double_to_string(iterator->second);
		else if (iterator->second != 1)
		{
			s_equation += double_to_string(iterator->second);
			s_equation += " * ";
		}
		if (iterator->first == 1)
			s_equation += "X";
		else if (iterator->first > 1)
		{
			s_equation += "X^";
			s_equation += double_to_string(iterator->first);
		}
	}

	s_equation += " =";

	//right side
	side = _right_side;
	iterator = side.begin();
	for (; iterator != side.end(); ++iterator)
	{
		s_equation += " ";
		if (iterator != side.begin())
		{
			if (is_greater(iterator->second, 0) || is_zero(iterator->second))
				s_equation += "+ ";
			else
			{
				s_equation += "- ";
				iterator->second *= -1;
			}
		}
		if (iterator->first == 0)
			s_equation += double_to_string(iterator->second);
		else if (iterator->second != 1)
		{
			s_equation += double_to_string(iterator->second);
			s_equation += " * ";
		}
		if (iterator->first == 1)
			s_equation += "X";
		else if (iterator->first > 1)
		{
			s_equation += "X^";
			s_equation += double_to_string(iterator->first);
		}
	}
	return (s_equation);
}

size_t	Polyn_Equation::get_max_degree(void) const
{
	return (max_degree);
}

std::ostream	&operator<<(std::ostream &o, Polyn_Equation const &rhs)
{
	o << rhs.convert_string();
	return (o);
}

/**
 * SUBFUNCTION FOR THE CLASS
 */

/**
 * check if the string is an equation :
 * it has one and only one equal sign
 * valide  : return the position of the equal sign
 * invalid : throw an exception
 */
size_t	Polyn_Equation::is_an_equation(std::string const &str_equation) const
{
	size_t position_equal = str_equation.find_first_of("=");
	if (position_equal == std::string::npos)
		throw NotAnEquation();
	else if (str_equation.find_first_of("=", position_equal + 1) != std::string::npos)
		throw NotAnEquation("more than one equal sign");
	return (position_equal);
}

/**
 * parse a side of the equation with each term (ex term: 2 * X ^ 3)
 * fill the map with the polyn and add the max_degree of the side
 */
void	Polyn_Equation::parse_side(bool is_right_side, std::string str_side)
{
	size_t 		i = 0;
	size_t		start;
	std::string 	sign = "+-";

	//std::cout << std::endl << "****** In parse_side ******" << std::endl;
	if (sign.find(str_side[0]) == sign.npos)
		str_side = '+' + str_side;
	while (i < str_side.length())
	{
		start = i;
		i = str_side.find_first_of(sign, i + 1);
		if (i == str_side.npos)
			i = str_side.length();
		if (i == start + 1)
			throw InvalidSide(is_right_side, "two operators in row");
		parse_term(is_right_side, std::string{str_side, start, i - start});
	}
}

/**
 * parse a term of a side of the equation
 * first parse the coefficient
 * then parse the degree
 * finally send both to the struct containing the polynom
 */

void	Polyn_Equation::parse_term(bool is_right_side, std::string str_term)
{
	double	coefficient;
	size_t	indice = 1;
	size_t	indice_degree = 0;

	//coeff part
	if (str_term.compare(0, 2, "+X") == 0)
		coefficient = 1;
	else if (str_term.compare(0, 2, "-X") == 0)
		coefficient = -1;
	else
	{
		try
		{
			coefficient = std::stof(str_term, &indice);
		}
		catch(const std::exception& e)
		{
			throw(InvalidTerm(is_right_side, "unvalid double for the coefficient"));
		}
	}

	// without X
	size_t	degree = 0;
	if (indice == str_term.length())
	{
		send_to_struct(is_right_side, coefficient, degree);
		return;
	}
	if (str_term[indice] == '*')
	{
		if (str_term[indice + 1] != 'X')
			throw(InvalidTerm(is_right_side, "* must be followed by X"));
		++indice;
	}
	if (str_term[indice] != 'X')
		throw(InvalidTerm(is_right_side, "\'" + std::string(1, str_term[indice]) + "\' character after the coefficient"));

	// just X
	degree = 1;
	++indice;
	if (indice == str_term.length())
	{
		send_to_struct(is_right_side, coefficient, degree);
		return;
	}
	else if (str_term[indice] != '^')
		throw(InvalidTerm(is_right_side, "X must be followed by ^"));
	++indice;

	// X ^ degree
	if (indice == str_term.length())
		throw(InvalidTerm(is_right_side, "^ must be followed by the degree"));
	try
	{
		degree = std::stoi(std::string(str_term, indice), &indice_degree);
	}
	catch(const std::exception& e)
	{
		throw(InvalidTerm(is_right_side, "unvalid size_t for the degree"));
	}
	indice += indice_degree;

	if (indice != str_term.length())
		throw(InvalidTerm(is_right_side, "\'" + std::string(1, str_term[indice]) + "\' character after the term"));
	send_to_struct(is_right_side, coefficient, degree);
}

/**
 * send the term with his coefficient and his degree
 * to the map of the corresponding side
 */
void	Polyn_Equation::send_to_struct(bool is_right_side, double coefficient, size_t degree)
{
	auto &buffer_map = (is_right_side) ? _right_side : _left_side;
	auto iterator = buffer_map.begin();

	iterator = buffer_map.find(degree);
	if (iterator == buffer_map.end())
	{
		buffer_map.insert(std::pair<size_t, double>(degree, coefficient));
		if (degree > max_degree)
			max_degree = degree;
	}
	else
	{
		if (is_zero(iterator->second + coefficient))
			buffer_map.erase(iterator);
		else
			iterator->second = iterator->second + coefficient;
	}
}

/**
 * Reduce the polynom
 * add all the element of right on the left one (*-1)
 * erase the empty ones and the right side
 * search the degree of the polynom
 */

void	Polyn_Equation::reduce_it(void)
{
	auto iterator_right = _right_side.begin();
	auto iterator_left = _left_side.begin();

	//add all right elements to left side
	for (; iterator_right != _right_side.end(); ++iterator_right)
	{
		iterator_left =  _left_side.find(iterator_right->first);
		if (iterator_left != _left_side.end())
			iterator_left->second -= iterator_right->second;
		else
			_left_side.insert(std::pair<size_t, double>(iterator_right->first, -1 * iterator_right->second));
	}

	//erase empty ones and the right side
	iterator_left = _left_side.begin();
	while (iterator_left != _left_side.end())
	{
		auto buffer = _left_side.end();
		if (is_zero(iterator_left->second))
			buffer = iterator_left;
		++iterator_left;
		if (buffer != _left_side.end())
			_left_side.erase(buffer);
	}
	if (_left_side.size() == 0)
		_left_side.insert(std::pair<size_t, double>(0, 0));
	_right_side.clear();
	_right_side.insert(std::pair<size_t, double>(0, 0));

	//search the max degree
	max_degree = _left_side.rbegin()->first;
}

/**
 * @brief print a complex number in a correct form
 *
 * @param real_number
 * @param imaginary_number
 */
void	print_complex_solution(double real_number, double imaginary_number)
{
	std::cout << Green << " ";
	if (!is_zero(real_number))
	{
		std::cout << double_to_string(real_number) << (is_greater(imaginary_number, 0) ? " + " : " - ");
		if (is_same(ft_abs(imaginary_number), 1))
			std::cout << "i";
		else
			std::cout << double_to_string(ft_abs(imaginary_number)) + "i";
	}
	else
	{
		std::cout << (imaginary_number > 0 ? "-" : "");
		if (is_same(ft_abs(imaginary_number), 1))
			std::cout << "i";
		else
			std::cout << double_to_string(ft_abs(imaginary_number)) + "i";
	}
	std::cout << Color_Off << std::endl;
}

/**
 * Solve the polynom
 */

void	Polyn_Equation::solve_it(void) const
{
	auto	iterator = _left_side.cbegin();
	double	a = 0;
	double	b = 0;
	double	c = 0;

	if (max_degree == 0)
	{
		if (is_zero(_left_side.begin()->second))
			std::cout << "All the number of C are solutions" << std::endl;
		else
			std::cout << "There is no solution" << std::endl;
	}
	else if (max_degree == 1)
	{
		for (; iterator != _left_side.cend(); ++iterator)
		{
			if (iterator->first == 1)
				a = iterator->second;
			else
				b = iterator->second;
		}
		std::cout << "The solution is:" << std::endl;
		std::cout << Green << double_to_string(-1 * b / a) << Color_Off << std::endl;
	}
	else if (max_degree == 2)
	{
		for (; iterator != _left_side.cend(); ++iterator)
		{
			if (iterator->first == 2)
				a = iterator->second;
			else if (iterator->first == 1)
				b = iterator->second;
			else
				c = iterator->second;
		}
		double delta = b * b - 4 * a * c;
		std::cout << UWhite "Discriminant" << Green " : " << double_to_string(delta) << Color_Off << std::endl;
		if (is_less(delta, 0))
		{
			std::cout << "Discriminant is strictly negative, there is two complex solutions :" << std::endl;
			print_complex_solution(-1 * b / (2 * a), -1 * ft_sqrt(-1 * delta) / (2 * a));
			print_complex_solution(-1 * b / (2 * a), ft_sqrt(-1 * delta) / (2 * a));
		}
		else if (is_zero(delta))
		{
			std::cout << "Discriminant is null, there is one solution :" << std::endl;
			std::cout << Green << double_to_string(-1 * b / (2 * a)) << Color_Off << std::endl;
		}
		else
		{
			std::cout << "Discriminant is positive, there is two solutions :" << std::endl;
			std::cout << Green << double_to_string((-1 * b + ft_sqrt(delta)) / (2 * a)) << std::endl;
			std::cout << Green << double_to_string((-1 * b - ft_sqrt(delta)) / (2 * a)) << std::endl;
		}
	}
	else
	{
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
	}
}