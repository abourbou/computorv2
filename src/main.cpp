
#include <iostream>
#include <csignal>
#include "parsing.hpp"
#include "string_function.hpp"
#include "Map_variable.hpp"
#include "test.hpp"
#include "execution.hpp"
#include "Singleton.hpp"

void signal_handler(int signal_num)
{
	std::cout << std::endl << "Interruption, the program will exit immediatly" << std::endl;
	exit(signal_num);
}

int	main(int argc, char **argv)
{
	static Singleton	*glob_var = Singleton::GetInstance();
	std::string	line;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	//TEST
	// test_map_variable();
	// test_computation();
	// test_syntax();
	//test_token();
	//test_value();
	//test_math_function();
	//TEST

	if (argc == 2)
	{
		exec_line(argv[1]);
		return (0);
	}
	else if (argc > 2)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << "----------------------------" << std::endl;
			std::cout << "command n " << i << std::endl;
			exec_line(argv[i]);
			if (glob_var->get_exit() == true)
				return (0);
		}
		return(0);
	}

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!glob_var->get_exit())
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
			break;
		exec_line(line);
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}