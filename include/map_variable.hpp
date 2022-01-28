#ifndef MAP_VARIABLE_HPP
# define MAP_VARIABLE_HPP

#include <map>
#include "IValue.hpp"

class map_variable
{
	private:
		std::map<std::string, IValue>	map;

	public:
		//coplien
		map_variable(void);
		~map_variable();

		//members
		
};

#endif