/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:10 by abourbou          #+#    #+#             */
/*   Updated: 2022/01/12 18:06:26 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "hello.hpp"

void signal_handler(int signal_num)
{
	std::cout << std::endl << "Interruption, the program will exit immediatly" << std::endl;
	exit(signal_num);
}

int	main(void)
{
	bool	exit = false;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);

	std::cout << "Welcome to computorv2!" << std::endl << std::endl;
	while(!exit)
	{
		std::cout << "> ";

		std::string line;
		if (!std::getline(std::cin, line))
			break;
		if (!line.compare("up"))
			std::cout << "get up command" << std::endl;
		std::cout << "line : [" << line << "]" << std::endl;
	}
	std::cout << std::endl << "End of the program" << std::endl;
	return (0);
}