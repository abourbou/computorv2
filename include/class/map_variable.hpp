#ifndef MAP_VARIABLE_HPP
# define MAP_VARIABLE_HPP

#include <map>
#include "Ivalue.hpp"

class map_variable
{
	private:
		std::map<std::string, Ivalue>	map;

	public:
		map_variable(void);
		~map_variable();
};

#endif