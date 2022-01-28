#ifndef IVariable_HPP
# define IVariable_HPP

#include <string>
#include <stdexcept>

class IVariable
{
	private:
		IVariable(void);
		IVariable &operator=(const IVariable &rhs);

	protected:
		//type : function or value
		//const :  cannot be for assignation
		const std::string _type;

	public:
		//coplien
		IVariable(std::string type);
		IVariable(const IVariable &rhs);
		virtual ~IVariable();

		//members
		std::string get_type() const;
		virtual std::string	to_string(void) const=0;
};

#endif