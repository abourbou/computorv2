
#include "Map_variable.hpp"

Map_variable::Map_variable(void)
{
	t_info info_buffer;

	//forbidden values
	info_buffer = {"exit", 0, Forbidden};
	_map_var.insert(std::pair<std::string, t_info>("EXIT", info_buffer));
	info_buffer = {"history", 0, Forbidden};
	_map_var.insert(std::pair<std::string, t_info>("HISTORY", info_buffer));

	//const values
	info_buffer = {"i", new Complex(0, 1), Reserved};
	_map_var.insert(std::pair<std::string, t_info>("I", info_buffer));
}

Map_variable::~Map_variable(void)
{
	for (auto it = _map_var.begin(); it != _map_var.end(); ++it)
	{
		if (it->second.secu_lvl != Forbidden)
			delete(it->second.var);
	}
}

void	Map_variable::add_var(std::string name, const IVariable *pvar)
{
	t_info	buffer_info = {name, pvar->clone(), Changeable};
	std::string caps_name = name;
	to_upper(caps_name);

	if (!is_alpha(name))
		throw(std::runtime_error("Variable must be only alphabetic caracters"));
	auto it = _map_var.find(caps_name);
	if (it != _map_var.end())
	{
		if (it->second.secu_lvl == Forbidden)
			throw(std::runtime_error("Forbidden name for variable"));
		else if (it->second.secu_lvl == Reserved)
			throw(std::runtime_error("Reserved name for variable"));
		else
			it->second = buffer_info;
	}
	else
		_map_var.insert(std::pair<std::string, t_info>(caps_name, buffer_info));
}

const IVariable *Map_variable::get_var(std::string name) const
{
	if (!is_alpha(name))
		throw(std::runtime_error("Variable must be only alphabetic caracters"));
	to_upper(name);
	auto it = _map_var.find(name);
	if (it != _map_var.end())
	{
		if (it->second.secu_lvl == Forbidden)
			throw(std::runtime_error("Forbidden name for variable"));
		return(it->second.var);
	}
	else
		throw(std::runtime_error("Unknow variable"));
}

void	Map_variable::show_map(void) const
{
	for (auto it = _map_var.begin(); it != _map_var.end(); ++it)
	{
		if (it->second.secu_lvl != Forbidden)
		{
			std::cout << it->second.name << " : " << it->second.var->to_string();
			std::cout << std::endl;
		}
	}
}