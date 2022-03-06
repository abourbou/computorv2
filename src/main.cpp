
#include <iostream>
#include <csignal>
#include "parsing.hpp"
#include "string_function.hpp"
#include "Map_variable.hpp"
#include "test.hpp"

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

void	exec_line(std::string line, bool &exit)
{
	static std::string	list_task[] = {"command","variable assignation",
										"function assignation", "computation", "polynom resolution"};
	int		n_task;
	std::string current_task = "parsing";

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

int	main(int argc, char **argv)
{
	Map_variable	my_map;
	bool		exit = false;
	std::string	line;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	//TEST
	//test_map_variable();
	//test_computation();
	test_input();
	//TEST

	if (argc == 2)
	{
		line = argv[1];
		exec_line(line, exit);
		return (0);
	}
	else if (argc > 2)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << "----------------------------" << std::endl;
			std::cout << "command n " << i << std::endl;
			exec_line(line, exit);
			if (exit == true)
				return (0);
		}
		return(0);
	}

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!exit)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
			break;
		exec_line(line, exit);
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}