/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivariable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/16 15:05:15 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>
#include <stdexcept>

class	Ivariable
{
	private:

	public:
	//coplien
		Ivariable(void);
		Ivariable(const Ivariable &rhs);
		virtual ~Ivariable(void);
		Ivariable &operator=(const Ivariable &rhs);

	//operator
		virtual Ivariable *operator+(const Ivariable *rhs) const;
		virtual Ivariable *operator-(const Ivariable *rhs) const;
		virtual Ivariable *operator*(const Ivariable *rhs) const;
		virtual Ivariable *operator/(const Ivariable *rhs) const;
		virtual Ivariable *operator%(const Ivariable *rhs) const;
		virtual Ivariable *matrice_multiplication(const Ivariable *rhs) const;

	//convert the variable into a string
		virtual std::string	to_string(void) const =0;
};

std::ostream	&operator<<(std::ostream &o, const Ivariable &rhs);

#endif