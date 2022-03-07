
#include <string>
#include "execution.hpp"

void	exec_line(std::string line)
{
	static std::string	list_task[] = {"command","variable assignation",
										"function assignation", "computation", "polynom resolution"};
	Task		n_task;
	std::string current_task = "parsing";

	try
	{
		line = regulate_string(line);
		std::cout << "line after regulation : [" << line << "]" << std::endl;
		n_task = find_task(line);
		current_task = list_task[n_task];
		std::cout << "task : " << current_task << std::endl;
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
	//static list_variable list;

	if (task == Command)
		exec_command(line);
	else if (task == Assign_var)
		exec_assign_value(line);
	else
	{
		std::cout << "Cannot executate task n" << task << " for now" << std::endl;
	}
}