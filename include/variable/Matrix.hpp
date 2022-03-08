#pragma once

#include <vector>
#include <string>
#include "IValue.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "string_function.hpp"

class Rational;

class Matrix	: public IValue
{
	private:
		//forbidden
		Matrix(void);

	protected:
		//variable
		size_t	_size[2] ={0, 0}; //size[0] : number line, size[1] : number column
		std::vector<std::vector<double> > _array;

	public:
		//coplien
		Matrix(std::string str);
		Matrix(size_t size[2], double value);
		Matrix(const Matrix &rhs);
		virtual ~Matrix();
		Matrix &operator=(const Matrix &rhs);

		//math operations
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *Matrix_mult(const IValue *rhs) const;

		//member
		virtual IVariable	*clone(void) const;
		virtual std::string	to_string(std::string str = "") const;
		virtual void		display(std::string str = "") const;
};

std::ostream	&operator<<(std::ostream &o, const Matrix &rhs);
