/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ivariable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:26:17 by root              #+#    #+#             */
/*   Updated: 2022/01/14 10:38:27 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>

class	IVariable
{
	private:
		std::string type =0;

	public:

	//basic
		IVariable(void);
		IVariable(std::string);
		IVariable(const IVariable &rhs);
		virtual ~IVariable(void);
		IVariable &operator=(const IVariable &rhs);

	//operator
		virtual IVariable &operator+(const IVariable &rhs) =0;
		virtual IVariable &operator-(const IVariable &rhs) =0;
		virtual IVariable &operator*(const IVariable &rhs) =0;
	
	//usefull
		virtual std::string	vartostr(void) const =0;
};

#endif