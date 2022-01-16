/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivariable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/16 09:45:32 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>
#include <stdexcept>

class	Ivariable
{
	private:
		Ivariable(void);

	public:
	//basic
		Ivariable(std::string str);
		Ivariable(const Ivariable &rhs);
		virtual ~Ivariable(void);
		Ivariable &operator=(const Ivariable &rhs);

	//operator
		virtual Ivariable *operator+(const Ivariable *rhs);
		virtual Ivariable *operator-(const Ivariable *rhs);
		virtual Ivariable *operator*(const Ivariable *rhs);
		virtual Ivariable *operator/(const Ivariable *rhs);
		virtual Ivariable *operator%(const Ivariable *rhs);
		virtual Ivariable *matrice_multiplication(const Ivariable *rhs);

	//usefull
		virtual std::string	vartostr(void) const =0;
};

#endif