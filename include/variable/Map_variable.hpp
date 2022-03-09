#pragma once

#include <string>
#include <map>
#include <algorithm>
#include "IValue.hpp"
#include "IVariable.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "string_function.hpp"

/**
 * @brief tool to stock, change, show and return IVariable
 */
class	Map_variable
{
	private:
		enum type_secu_lvl { Forbidden, Reserved, Changeable };

		typedef struct	s_info
		{
			std::string	name;
			IVariable	*var;
			type_secu_lvl	secu_lvl;
		}				t_info;
		Map_variable(const Map_variable &rhs);
		Map_variable &operator=(const Map_variable &rhs);

	protected:
		std::map<std::string, t_info>	_map_var;

	public:
		//coplien
		Map_variable(void);
		virtual ~Map_variable(void);

		//members
		void		add_var(std::string name, const IVariable *pvar);
		const IVariable	*get_var(std::string name) const;
		bool		is_var(std::string name) const;
		void		show_map(void) const;
};
