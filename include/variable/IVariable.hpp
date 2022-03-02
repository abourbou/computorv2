#pragma once
#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>
#include <stdexcept>

class IVariable
{
	private:
		IVariable(void);
		IVariable &operator=(const IVariable &rhs);

	protected:
		//type : function or value
		const std::string _type;

	public:
		//coplien
		IVariable(std::string type);
		IVariable(const IVariable &rhs);
		virtual ~IVariable();

		//members
		std::string		get_type() const;
		virtual IVariable	*clone(void) const =0;
		virtual std::string	to_string(void) const =0;
		virtual void		display(std::string var= "") const =0;
};

#endif