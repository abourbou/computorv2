/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivalue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/17 13:56:18 by abourbou         ###   ########lyon.fr   */
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
		Ivalue(void);

	public:
		Ivalue(bool is_constant);
		Ivalue(const Ivalue &rhs);
		virtual ~Ivalue(void);
		Ivalue &operator=(const Ivalue &rhs);

	//operator
		virtual Ivalue *operator+(const Ivalue *rhs) const;
		virtual Ivalue *operator-(const Ivalue *rhs) const;
		virtual Ivalue *operator*(const Ivalue *rhs) const;
		virtual Ivalue *operator/(const Ivalue *rhs) const;
		virtual Ivalue *operator%(const Ivalue *rhs) const;
		virtual Ivalue *matrice_multiplication(const Ivalue *rhs) const;

	//convert the variable into a string
		virtual std::string	to_string(void) const =0;
};

std::ostream	&operator<<(std::ostream &o, const Ivalue &rhs);

#endif