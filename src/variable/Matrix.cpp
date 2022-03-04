
#include "Matrix.hpp"

/**
 * @brief Construct a new Matrix object
 *
 * @param str format accepted : [[a,b];[c,d]...]
 * @param is_const
 */
Matrix::Matrix(std::string str) : IValue()
{
	size_t	i = 0, buffer, nbr_lign = 0, length_lign = 0;
	std::vector<double>	vect_buffer;

	erase_white_space(str);
	if (str.empty() || str.front() != '[' || str.back() != ']')
		throw(std::runtime_error("invalid Matrix"));
	str.erase(0, 1);
	str.erase(str.size() - 1, 1);
	while(i < str.size())
	{
		vect_buffer.clear();
		length_lign = 0;
		if (nbr_lign != 0 && str[i++] != ';')
			throw(std::runtime_error("invalid Matrix"));
		if (str[i] != '[')
			throw(std::runtime_error("invalid Matrix"));
		++i;
		while (i != ']' && i < str.size())
		{
			if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
				throw(std::runtime_error("invalid Matrix"));
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
			throw(std::runtime_error("invalid Matrix"));
		if (str[i] != ']')
			throw(std::runtime_error("invalid Matrix"));
		this->_array.push_back(vect_buffer);
		++i;
		++nbr_lign;
	}
	_size[0] = nbr_lign;
}

Matrix::Matrix(size_t size[2], double value): IValue()
{
	std::vector<double> buffer;

	_size[0] = size[0];
	_size[1] = size[1];
	if (_size[0] == 0 || _size[1] == 0)
		throw(std::runtime_error("invalid Matrix"));
	buffer = std::vector<double>(_size[1], value);
	_array.reserve(_size[0]);
	for(size_t i = 0; i < _size[0]; ++i)
		_array.push_back(buffer);
}

Matrix::Matrix(const Matrix &rhs) : IValue(rhs)
{
	std::vector<double> buffer;

	_size[0] = rhs._size[0];
	_size[1] = rhs._size[1];
	for (size_t i = 0; i < _size[0]; ++i)
	{
		std::vector<double>().swap(buffer);
		copy(rhs._array[i].begin(), rhs._array[i].end(), back_inserter(buffer));
		_array.push_back(buffer);
	}
}

Matrix::~Matrix(void)
{
	std::vector<std::vector<double> >().swap(_array);
}

Matrix	&Matrix::operator=(const Matrix &rhs)
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

IValue	*Matrix::operator+(const IValue *rhs) const
{
	const Matrix *m_var;
	Matrix *new_Matrix;

	if ((m_var = dynamic_cast<const Matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("different size matrices, can't add"));
		new_Matrix = new Matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_Matrix->_array[i][j] += m_var->_array[i][j];
		}
		return(new_Matrix);
	}
	else
		throw(std::runtime_error("invalid type for addition"));
}

IValue	*Matrix::operator-(const IValue *rhs) const
{
	const Matrix *m_var;
	Matrix *new_Matrix;

	if ((m_var = dynamic_cast<const Matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("different size matrices, can't sub"));
		new_Matrix = new Matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_Matrix->_array[i][j] -= m_var->_array[i][j];
		}
		return(new_Matrix);
	}
	else
		throw(std::runtime_error("invalid type for substraction"));
}

IValue	*Matrix::operator*(const IValue *rhs) const
{
	const Matrix *m_var;
	const Rational *r_var;
	Matrix *new_Matrix;

	if ((m_var = dynamic_cast<const Matrix *>(rhs)))
	{
		if (m_var->_size[0] != _size[0] || m_var->_size[1] != _size[1])
			throw(std::runtime_error("matrices of different size, can't mult"));
		new_Matrix = new Matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_Matrix->_array[i][j] *= m_var->_array[i][j];
		}
		return(new_Matrix);
	}
	else if ((r_var = dynamic_cast<const Rational*>(rhs)))
	{
		new_Matrix = new Matrix(*this);
		for (size_t i = 0; i < _size[0]; ++i)
		{
			for (size_t j = 0; j < _size[1]; ++j)
				new_Matrix->_array[i][j] *= r_var->getvalue();
		}
		return(new_Matrix);
	}
	else
		throw(std::runtime_error("invalid type for multiplication"));
}

IValue *Matrix::Matrix_mult(const IValue *rhs) const
{
	const Matrix *m_var;
	Matrix *new_Matrix;

	if ((m_var = dynamic_cast<const Matrix *>(rhs)))
	{
		if (_size[1] != m_var->_size[0])
			throw(std::runtime_error("matrice with invalid size for matricial multiplication"));
		size_t	new_size[2] = {_size[0], m_var->_size[1]};
		new_Matrix = new Matrix(new_size, 0);
		for (size_t i = 0; i < new_size[0]; ++i)
			for (size_t j = 0; j < m_var->_size[1]; ++j)
				for (size_t k = 0; k < _size[1]; ++k)
					new_Matrix->_array[i][j] += _array[i][k] * m_var->_array[k][j];
		return (new_Matrix);
	}
	else
		throw(std::runtime_error("invalid type for matricial multiplication"));
	return(0);
}

IVariable	*Matrix::clone(void) const
{
	return (new Matrix(*this));
}

std::string	Matrix::to_string(void) const
{
	std::string	str = "[";

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
			str += ";";
	}
	str += "]";
	return(str);
}

void	Matrix::display(std::string str) const
{
	(void)str;
	for (size_t i =0; i < _size[0]; ++i)
	{
		std::cout << '[';
		for(size_t j = 0; j < _size[1]; ++j)
		{
			//std::cout << " i : " << i << ", j : " << j << std::endl;
			std::cout << ' ' + double_to_string(_array[i][j]) + ' ';
			if (j < _size[1] - 1)
				std::cout << ',';
		}
		std::cout << ']' << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Matrix &rhs)
{
	o << rhs.to_string();
	return (o);
}