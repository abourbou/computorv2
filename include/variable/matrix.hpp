#ifndef matrix_HPP
# define matrix_HPP

#include <vector>
#include <string>
#include "Ivalue.hpp"
#include "rational.hpp"
#include "complex.hpp"
#include "string_function.hpp"

class rational;

class matrix	: public Ivalue
{
	private:
		//forbidden
		matrix(void);

	protected:
		//variable
		size_t	_size[2] ={0, 0}; //size[0] : number line, size[1] : number column
		std::vector<std::vector<double> > _array;

	public:
		//coplien
		matrix(std::string str);
		matrix(size_t size[2], double value);
		matrix(const matrix &rhs);
		virtual ~matrix();
		matrix &operator=(const matrix &rhs);

		//math operations
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *matrix_mult(const Ivalue *rhs) const;

		//member
		//std::vector<std::vector<double> >	clone(void) const;
		virtual std::string	to_string(void) const;
		std::string		to_string_inline(void) const;
};

std::ostream	&operator<<(std::ostream &o, const matrix &rhs);

#endif