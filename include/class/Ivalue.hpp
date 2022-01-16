/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivalue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/16 22:53:50 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVALUE_HPP
# define IVALUE_HPP

#include <string>
#include <stdexcept>

class	Ivalue
{
	private:

	public:
	//coplien
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
		virtual Ivalue *matrice_multiplication(const Ivalue *rhs) const;

	//convert the variable into a string
		virtual std::string	to_string(void) const =0;
};

std::ostream	&operator<<(std::ostream &o, const Ivalue &rhs);

#endif