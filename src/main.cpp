/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:10 by abourbou          #+#    #+#             */
/*   Updated: 2022/01/13 22:26:14 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "parsing.hpp"

void signal_handler(int signal_num)
{
	std::cout << std::endl << "Interruption, the program will exit immediatly" << std::endl;
	exit(signal_num);
}

int	main(void)
{
	bool	exit = false;
	int		task;
	std::string	tracking = "line";
	std::string line;
	std::string		localisation[] = {"command","assignation of a variable", 
	"assignation of a function", "computation", "resolution of a polynom"};
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!exit)
	{
		std::cout << "> ";
		tracking = "line";

		if (!std::getline(std::cin, line))
			break;
		std::cout << "line : [" << line << "]" << std::endl;
		try
		{
			line = regulate_string(line);
			std::cout << "line after regulation : [" << line << "]" << std::endl;
			task = find_task(line);
			tracking = localisation[task];
			std::cout << "task : " << tracking << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error on the " + tracking + " : ";
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}