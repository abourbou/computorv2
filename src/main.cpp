
#include <iostream>
#include <csignal>
#include "parsing.hpp"
#include "Rational.hpp"
#include "Complex.hpp"
#include "Matrix.hpp"
#include "Map_variable.hpp"
#include "string_function.hpp"

void signal_handler(int signal_num)
{
	std::cout << std::endl << "Interruption, the program will exit immediatly" << std::endl;
	exit(signal_num);
}

void	exec_task(int task, bool &exit, std::string line)
{
	//static list_variable list;

	if (task == Command)
		exec_command(line, exit);
	else if (task == Assign_var)
		exec_assign_value(line);
	else
	{
		std::cout << "Cannot executate task n" << task << " for now" << std::endl;
	}
}

int	main(void)
{
	Map_variable	my_map;
	bool		exit = false;
	int			n_task;
	std::string	current_task = "parsing";
	std::string	line;
	std::string	list_task[] = {"command","variable assignation",
	"function assignation", "computation", "polynom resolution"};
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	//TEST

	//TEST

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!exit)
	{
		std::cout << "> ";
		current_task = "parsing";

		if (!std::getline(std::cin, line))
			break;
		std::cout << "line : [" << line << "]" << std::endl;
		try
		{
			line = regulate_string(line);
			std::cout << "line after regulation : [" << line << "]" << std::endl;
			n_task = find_task(line);
			current_task = list_task[n_task];
			std::cout << "task : " << current_task << std::endl;
			exec_task(n_task, exit, line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error in the " + current_task << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}