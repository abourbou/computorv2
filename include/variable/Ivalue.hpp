/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivalue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/21 10:54:08 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVALUE_HPP
# define IVALUE_HPP

#include <string>
#include <stdexcept>
#include "Ivariable.hpp"

class	Ivalue : public Ivariable
{
	private:
	//coplien

	public:
		Ivalue(void);
		Ivalue(const Ivalue &rhs);
		virtual ~Ivalue(void);
		Ivalue &operator=(const Ivalue &rhs);

	//operator
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;
		virtual Ivalue *operator%(const Ivalue *rhs) const;
		virtual Ivalue *operator^(const Ivalue *rhs) const;
		virtual Ivalue *matrix_mult(const Ivalue *rhs) const;
};

std::ostream	&operator<<(std::ostream &o, const Ivalue &rhs);

#endif