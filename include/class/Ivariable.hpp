#ifndef IVARIABLE_HPP
# define IVARIABLE_HPP

#include <string>

class Ivariable
{
	private:
		Ivariable(void);
		Ivariable &operator=(const Ivariable &rhs);

	protected:
		//type : function or value
		//constant :  cannot be for assignation
		const std::string _type;
		const bool _constant;

	public:
		//coplien
		Ivariable(std::string type, bool is_constant);
		Ivariable(const Ivariable &rhs);
		virtual ~Ivariable();

		//members
		std::string get_type() const;

};

#endif