/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivalue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/28 10:07:48 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IValue_HPP
# define IValue_HPP

#include <string>
#include <stdexcept>
#include "IVariable.hpp"

class	IValue : public IVariable
{
	private:
	//coplien

	public:
		IValue(void);
		IValue(const IValue &rhs);
		virtual ~IValue(void);
		IValue &operator=(const IValue &rhs);

	//operator
		virtual IValue *operator+(const IValue *rhs) const;
		virtual IValue *operator-(const IValue *rhs) const;
		virtual IValue *operator*(const IValue *rhs) const;
		virtual IValue *operator/(const IValue *rhs) const;
		virtual IValue *operator%(const IValue *rhs) const;
		virtual IValue *operator^(const IValue *rhs) const;
		virtual IValue *Matrix_mult(const IValue *rhs) const;
};

std::ostream	&operator<<(std::ostream &o, const IValue &rhs);

#endif