
#include <string>
#include "execution.hpp"
#include "parsing.hpp"
#include "string_function.hpp"

/**
 * @brief check if the line doesn't have forbidden character + put it in a correct way
 *
 * @param line
 * @return std::string
 */

std::string	regulate_string(std::string line)
{
	std::string	allowed_symboles("+-*/%^()[],;=?.");

	erase_white_space(line);
	auto it = line.begin();
	while (it < line.end())
	{
		char &c = *it;
		if (!isalnum(c) && allowed_symboles.find(c) == std::string::npos)
			throw(std::runtime_error("Forbidden character"));
		++it;
	}
	return(line);
}

//determine if f(x) is a computation or getting the variable f
Task	compt_or_getvar(std::string str)
{
	Map_variable &map = Singleton::GetInstance()->get_map_variable();
	std::string var, fct;
	size_t	start, end;

	start = str.find("(");
	if (start == std::string::npos || start == 0)
		return (Computation);
	fct = str.substr(0, start);
	if (!map.is_var(fct))
		throw std::runtime_error("unknown function");

	//find expr
	end = str.find(")");
	if (end == std::string::npos || end <= start + 1 || end != str.size() - 1)
		throw std::runtime_error("unvalid syntax");
	var = str.substr(start + 1, end - start - 1);

	const IVariable *Ivar = map.get_var(fct);
	if (Ivar->get_type() != variable_type::function)
		throw std::runtime_error("variable isn't a function");
	const IFunction *Ifct = static_cast<const IFunction *>(Ivar);
	if (Ifct->get_var() == var)
		return (Get_variable);
	return (Computation);
}

/**
 * @brief Find the task asked :
 * assignation, computation, resolution equation etc...
 *
 * @param line
 * @return int
 */
Task		find_task(std::string line)
{
	auto nb_equal = std::count(line.begin(), line.end(), '=');
	if (nb_equal == 0)
		return (Command);
	else if (nb_equal == 1)
	{
		auto nb_interrogation = std::count(line.begin(), line.end(), '?');
		auto it_equal = std::find(line.begin(), line.end(), '=');
		if (nb_interrogation == 0)
		{
			//form f(x) = expr(x)
			if (std::count(line.begin(), it_equal, '(' ) > 0 ||
				std::count(line.begin(), it_equal, ')') > 0)
				return(Assign_func);
			//form a = computation
			return(Assign_var);
		}
		else if (nb_interrogation == 1)
		{
			auto it_interrog = std::find(line.begin(), line.end(), '?');
			if (it_interrog + 1 != line.end())
				throw(std::runtime_error("? symbol must be at the end of the command"));
			//form expr1 =?
			if (it_equal + 1 == it_interrog)
			{
				std::string expr1 = line.substr(0, line.size() - 2);
				if (is_alpha(expr1))
					return(Get_variable);
				for (char c : expr1)
				{
					if (!isalpha(c) && c != '(' && c != ')')
						return (Computation);
				}
				//form f(var) =?
				return (compt_or_getvar(expr1));
			}
			//form expr1 = expr2 ?
			return (Resolv_Polyn);
		}
		throw(std::runtime_error("more than one question mark sign"));
	}
	else
	{
		throw(std::runtime_error("More than one equal sign"));
	}
	return (Assign_func);
}



void	exec_line(std::string line)
{
	static std::string	list_task[] = {"command","variable assignation",
						"function assignation", "computation",
						"get variable", "polynom resolution"};
	Task		n_task;
	std::string current_task = "parsing";

	try
	{
		line = regulate_string(line);
		n_task = find_task(line);
		current_task = list_task[n_task];
		exec_task(n_task, line);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error in the " + current_task << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void	exec_task(Task task, std::string line)
{
	//TODO erase it
	static std::string	list_task[] = {"command","variable assignation",
						"function assignation", "computation",
						"get variable", "polynom resolution"};
	std::cout << "task : " << list_task[task] << std::endl;
	if (task == Command)
		exec_command(line);
	else if (task == Assign_var)
		exec_assign_var(line);
	else if (task == Assign_func)
		exec_assign_fct(line);
	else if (task == Computation)
		exec_computation(line);
	else if (task == Get_variable)
		exec_get_var(line);
	else if (task == Resolv_Polyn)
		exec_polyn(line);
	else
	{
		std::cout << "Cannot executate task n" << task << " for now" << std::endl;
	}
}