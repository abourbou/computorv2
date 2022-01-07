/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:10 by abourbou          #+#    #+#             */
/*   Updated: 2022/01/07 10:54:02 by abourbou         ###   ########lyon.fr   */
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
		std::cout << "line : [" << line << "]" << std::endl;
	}
	std::cout << std::endl << "Goodbye, I hope you had a nice time here!" << std::endl;
	return (0);
}