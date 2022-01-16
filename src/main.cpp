/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:10 by abourbou          #+#    #+#             */
/*   Updated: 2022/01/16 15:07:24 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "parsing.hpp"
#include "rational.hpp"

void signal_handler(int signal_num)
{
	std::cout << std::endl << "Interruption, the program will exit immediatly" << std::endl;
	exit(signal_num);
}

void	exec_task(int task, bool &exit, std::string line)
{
	//static list_variable list;

	if (task == 0)
		exec_command(line, exit);
	else
	{
		std::cout << "Cannot executate task n" << task << " for now" << std::endl;
	}
}

int	main(void)
{
	bool		exit = false;
	int			n_task;
	std::string	current_task = "line";
	std::string	line;
	std::string	list_task[] = {"command","variable assignation", 
	"function assignation", "computation", "polynom resolution"};
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	//TEST
	rational a(2);
	rational b(4);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "a + b : " << *(a + &b) << std::endl;
	std::cout << "a - b : " << *(a - &b) << std::endl;
	std::cout << "a * b : " << *(a * &b) << std::endl;
	std::cout << "a / b : " << *(a / &b) << std::endl;
	std::cout << "a % b : " << *(a % &b) << std::endl;
	//END TEST

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!exit)
	{
		std::cout << "> ";
		current_task = "line";

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
			std::cerr << "Error on the " + current_task + " : ";
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}