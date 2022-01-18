#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>
#include <stdexcept>

class Ivariable
{
	private:
		Ivariable(void);
		Ivariable &operator=(const Ivariable &rhs);

	protected:
		//type : function or value
		//const :  cannot be for assignation
		const std::string _type;
		const bool _const;

	public:
		//coplien
		Ivariable(std::string type, bool is_const);
		Ivariable(const Ivariable &rhs);
		virtual ~Ivariable();

		//members
		std::string get_type() const;
		virtual std::string	to_string(void) const=0;
};

#endif