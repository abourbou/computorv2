
#include "matrix.hpp"

/**
 * @brief Construct a new matrix object
 *
 * @param str format accepted : [[a,b];[c,d]]
 * @param is_const
 */
matrix::matrix(std::string str, bool is_const) : Ivalue(is_const)
{
	size_t	i = 0;
	size_t	nbr_lign = 0;
	size_t	length_lign = 0;
	std::vector<double>	vect_buffer;

	erase_white_space(str);
	if (str.empty() || str.front() != '[' || str.back() != ']')
		throw(std::runtime_error("invalid matrix"));
	str.erase(0, 1);
	str.erase(str.size() - 1, 1);
	while(i < str.size())
	{
		vect_buffer.clear();
		length_lign = 0;
		if (str[i] != '[')
			throw(std::runtime_error("invalid matrix"));
		++i;
		while (i != ']' && i <str.size())
		{
			if (!isdigit(str[i]))
				throw(std::runtime_error("invalid matrix"));
			vect_buffer.push_back(std::stod(&str[i], &i));
			++length_lign;
			if (i != ',')
				break;
			++i;
		}
		if (_size[1] == 0)
			_size[1] = length_lign;
		else if (_size[1] != length_lign)
			throw(std::runtime_error("invalid matrix"));
		if (i != ']')
			throw(std::runtime_error("invalid matrix"));
		this->_array.push_back(vect_buffer);
		++i;
		++nbr_lign;
	}
	_size[0] = nbr_lign;
	std::cout << "nbr lign : " << _size[0] << "length lign : " << _size[1] <<std::endl;
}

//operation

//member
std::string	matrix::to_string(void) const
{
	std::string	str = "";

	for (size_t i =0; i < _size[0]; ++i)
	{
		str += '[';
		for(size_t j = 0; j < _size[1]; ++j)
		{
			str += ' ';
			str += double_to_string(_array[i][j]);
			str += ' ';
			if (j != _size[i] - 1)
				str += ',';
		}
		str += "]\n";
	}
	return(str);
}

//for the function incase we need to show it
std::string	matrix::to_string_inline(void) const
{
	std::string	str = "";

	return(str);
}

std::ostream	&operator<<(std::ostream &o, const matrix &rhs)
{
	o << rhs.to_string();
	return (o);
}