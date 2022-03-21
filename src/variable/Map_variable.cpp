
#include "Map_variable.hpp"

void	Map_variable::insert_var(std::string name, IVariable *var, type_secu_lvl lvl)
{
	std::string caps_name = name;
	to_upper(caps_name);
	t_info info_buffer = {name, var, lvl};

	_map_var.insert(std::pair<std::string, t_info>(caps_name, info_buffer));
}

Map_variable::Map_variable(void)
{
	t_info info_buffer;

	//forbidden values
	insert_var("exit", 0, Forbidden);
	insert_var("test", 0, Forbidden);

	//const values
	insert_var("i", new Complex(0, 1), Reserved);
	insert_var("pi", new Rational(3.141592653), Reserved);
	insert_var("e", new Rational(2.71828182846), Reserved);

	//const function
	insert_var("sqrt", new Explic_fct("sqrt", fct_sqrt), Reserved);
	insert_var("norm", new Explic_fct("norm", fct_norm), Reserved);
	insert_var("sin", new Explic_fct("sin", fct_sin), Reserved);
	insert_var("cos", new Explic_fct("cos", fct_cos), Reserved);
	insert_var("tan", new Explic_fct("tan", fct_tan), Reserved);
	insert_var("exp", new Explic_fct("exp", fct_exp), Reserved);
	insert_var("ln", new Explic_fct("ln", fct_ln), Reserved);
	insert_var("log", new Explic_fct("log", fct_log), Reserved);
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
		throw(std::runtime_error("variable must be only alphabetic caracters"));
	auto it = _map_var.find(caps_name);
	if (it != _map_var.end())
	{
		if (it->second.secu_lvl == Forbidden)
		{
			delete buffer_info.var;
			throw(std::runtime_error("forbidden name for variable"));
		}
		else if (it->second.secu_lvl == Reserved)
		{
			delete buffer_info.var;
			throw(std::runtime_error("reserved name for variable"));
		}
		else
		{
			delete it->second.var;
			it->second = buffer_info;
		}
	}
	else
		_map_var.insert(std::pair<std::string, t_info>(caps_name, buffer_info));
}

void	Map_variable::remove_var(std::string name)
{
	to_upper(name);
	auto it = _map_var.find(name);
	if (it == _map_var.end())
		throw(std::runtime_error("impossible to remove variable"));
	else if (it->second.secu_lvl != Changeable)
		throw(std::runtime_error("impossible to remove variable"));
	if (it->second.var->get_type() != variable_type::function)
		delete it->second.var;
	_map_var.erase(it);
}

const IVariable *Map_variable::get_var(std::string name) const
{
	if (name.empty())
		throw std::runtime_error("empty variable");
	if (!is_alpha(name))
		throw(std::runtime_error("variable must be only alphabetic caracters"));
	to_upper(name);
	auto it = _map_var.find(name);
	if (it != _map_var.end())
	{
		if (it->second.secu_lvl == Forbidden)
			throw(std::runtime_error("forbidden name for variable"));
		return(it->second.var);
	}
	else
		throw(std::runtime_error("unknow variable"));
}

/**
 * @brief check if a variable exist on the map
 *
 * @param name
 * @return boolean
 */
bool		Map_variable::is_var(std::string name) const
{
	if (!is_alpha(name))
		throw(std::runtime_error("variable must be only alphabetic caracters"));
	to_upper(name);
	auto it = _map_var.find(name);
	if (it != _map_var.end())
	{
		if (it->second.secu_lvl == Forbidden)
			return(false);
		return(true);
	}
	return (false);
}

void	Map_variable::show_map(void) const
{
	for (auto it = _map_var.begin(); it != _map_var.end(); ++it)
	{
		if (it->second.secu_lvl != Forbidden)
		{
			std::cout << BWhite << it->second.name << "\t" Color_Off;
			if (it->second.var->get_type() == variable_type::function)
				std::cout<< BBlue;
			else
				std::cout << BYellow;
			std::cout << it->second.var->to_string() << Color_Off << std::endl;
		}
	}
}