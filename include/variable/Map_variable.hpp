#ifndef MAP_VARIABLE_HPP
# define MAP_VARIABLE_HPP

#include <string>
#include <map>
#include "IValue.hpp"
#include "IVariable.hpp"


class	Map_variable
{
	private:
		typedef struct s_info
		{
		std::string	name;
		bool		is_const;
		}		t_info;
		Map_variable(const Map_variable &rhs);
		Map_variable &operator=(const Map_variable &rhs);

	protected:
		std::map<t_info, IVariable *>	_map_var;

	public:
		//coplien
		Map_variable(void);
		virtual ~Map_variable(void);

		//members
		void		add_var(std::string name, IVariable *pvar);
		IVariable	*get_var(std::string name);
		void		show_map(void) const;
};

#endif