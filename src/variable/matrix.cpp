
#include "matrix.hpp"

/**
 * @brief Construct a new matrix object
 *
 * @param str format accepted : [[a,b];[c,d]]
 * @param is_const
 */
matrix::matrix(std::string str, bool is_const) : Ivalue(is_const)
{
	size_t	i = 0, buffer, nbr_lign = 0, length_lign = 0;
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
		if (nbr_lign != 0 && str[i++] != ';')
			throw(std::runtime_error("invalid matrix"));
		if (str[i] != '[')
			throw(std::runtime_error("invalid matrix"));
		++i;
		while (i != ']' && i < str.size())
		{
			if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
				throw(std::runtime_error("invalid matrix"));
			vect_buffer.push_back(std::stod(&str[i], &buffer));
			i += buffer;
			++length_lign;
			if (str[i] != ',')
				break;
			++i;
		}
		if (_size[1] == 0)
			_size[1] = length_lign;
		else if (length_lign != _size[1])
			throw(std::runtime_error("invalid matrix"));
		if (str[i] != ']')
			throw(std::runtime_error("invalid matrix"));
		this->_array.push_back(vect_buffer);
		++i;
		++nbr_lign;
	}
	_size[0] = nbr_lign;
}

matrix::matrix(size_t size[2], double value, bool is_const): Ivalue(is_const)
{
	std::vector<double> buffer;

	_size[0] = size[0];
	_size[1] = size[1];
	if (_size[0] == 0 || _size[1] == 0)
		throw(std::runtime_error("invalid matrix"));
	buffer = std::vector<double>(_size[1], value);
	_array.reserve(_size[0]);
	for(size_t i = 0; i < _size[0]; ++i)
		_array.push_back(buffer);
}

matrix::matrix(const matrix &rhs) : Ivalue(rhs)
{
	std::vector<double> buffer;

	_size[0] = rhs._size[0];
	_size[1] = rhs._size[1];
	std::vector<std::vector<double>>().swap(_array);
	for (size_t i = 0; i < _size[0]; ++i)
	{
		std::vector<double>().swap(buffer);
		copy(rhs._array[i].begin(), rhs._array[i].end(), back_inserter(buffer));
		_array.push_back(buffer);
	}
}

matrix::~matrix(void)
{
	std::vector<std::vector<double> > buffer;

	_array.swap(buffer);
}

matrix	&matrix::operator=(const matrix &rhs)
{
	std::vector<double> buffer;

	if (_const)
		throw(std::runtime_error("can not reassign a const variable"));
	_size[0] = rhs._size[0];
	_size[1] = rhs._size[1];
	std::vector<std::vector<double>>().swap(_array);
	for (size_t i = 0; i < _size[0]; ++i)
	{
		std::vector<double>().swap(buffer);
		copy(rhs._array[i].begin(), rhs._array[i].end(), back_inserter(buffer));
		_array.push_back(buffer);
	}
	return(*this);
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
			//std::cout << " i : " << i << ", j : " << j << std::endl;
			str += ' ';
			str += double_to_string(_array[i][j]);
			str += ' ';
			if (j < _size[1] - 1)
				str += ',';
		}
		str += ']';
		if (i < _size[0] - 1)
			str += "\n";
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