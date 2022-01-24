
#include "matrix.hpp"

/**
 * @brief Construct a new matrix object
 *
 * @param str format accepted : [[a,b];[c,d]]
 * @param is_const
 */
matrix::matrix(std::string str) : Ivalue()
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

matrix::matrix(size_t size[2], double value): Ivalue()
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

Ivalue	*matrix::operator+(const Ivalue *rhs) const
{
	const matrix *m_var;
	matrix *new_matrix;

	if ((m_var = dynamic_cast<const matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("different size matrices, can't add"));
		new_matrix = new matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_matrix->_array[i][j] += m_var->_array[i][j];
		}
		return(new_matrix);
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

Ivalue	*matrix::operator-(const Ivalue *rhs) const
{
	const matrix *m_var;
	matrix *new_matrix;

	if ((m_var = dynamic_cast<const matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("different size matrices, can't sub"));
		new_matrix = new matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_matrix->_array[i][j] -= m_var->_array[i][j];
		}
		return(new_matrix);
	}
	else
		throw(std::runtime_error("invalid type for substraction"));
}

Ivalue	*matrix::operator*(const Ivalue *rhs) const
{
	const matrix *m_var;
	const rational *r_var;
	matrix *new_matrix;

	if ((m_var = dynamic_cast<const matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("matrices of different size, can't mult"));
		new_matrix = new matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_matrix->_array[i][j] *= m_var->_array[i][j];
		}
		return(new_matrix);
	}
	else if ((r_var = dynamic_cast<const rational*>(rhs)))
	{
		new_matrix = new matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_matrix->_array[i][j] *= r_var->getvalue();
		}
		return(new_matrix);
	}
	else
		throw(std::runtime_error("invalid type for multiplication"));
}

Ivalue *matrix::matrix_mult(const Ivalue *rhs) const
{
	const matrix *m_var;
	matrix *new_matrix;

	if ((m_var = dynamic_cast<const matrix *>(rhs)))
	{
		if (_size[1] != m_var->_size[0])
			throw(std::runtime_error("matrice with invalid size for matricial multiplication"));
		size_t	new_size[2] = {_size[0], m_var->_size[1]};
		new_matrix = new matrix(new_size, 0);
		for (size_t i = 0; i < new_size[0]; ++i)
			for (size_t j = 0; j < m_var->_size[1]; ++j)
				for (size_t k = 0; k < _size[1]; ++k)
					new_matrix->_array[i][j] += _array[i][k] * m_var->_array[k][j];
		return (new_matrix);
	}
	else
		throw(std::runtime_error("invalid type for matricial multiplication"));
	return(0);
}

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