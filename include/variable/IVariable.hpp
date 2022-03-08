#pragma once

#include <string>
#include <stdexcept>

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
		variable_type _type;

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
		virtual std::string	to_string(std::string str = "") const =0;
		virtual void		display(std::string var= "") const =0;
};
