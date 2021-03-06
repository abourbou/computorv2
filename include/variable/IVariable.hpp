#pragma once

#include <string>
#include <stdexcept>
#include "color_code.hpp"

enum class variable_type
{
	rational,
	complex,
	matrix,
	function,
};

class IVariable
{
	private:
		IVariable(void);
		const variable_type _type;

//	protected:

	public:
		//coplien
		IVariable(variable_type type);
		IVariable(const IVariable &rhs);
		IVariable &operator=(const IVariable &rhs);
		virtual ~IVariable();

		//members
		variable_type		get_type() const;
		virtual IVariable	*clone(void) const =0;
		virtual std::string	to_string(void) const =0;
		virtual void		display(void) const =0;
};
