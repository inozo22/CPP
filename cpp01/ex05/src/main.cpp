/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 12:14:36 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "you have to put for arguments as \"./Harl s1\"" << std::endl;
		return (1);
	}
	std::string str = av[1];
	if (str == UTEST || str == LTEST)
	{
		std::cout << GREEN << "\n=====  TEST  =====\n" << CLEAR;
		Harl	harl_test;
		std::cout << GREEN << "input \"DEBUG\"\n" << CLEAR;
		harl_test.complain("DEBUG");
		std::cout << RED << "\ninput \"debug\"\n" << CLEAR;
		harl_test.complain("debug");
		std::cout << GREEN << "\ninput \"INFO\"\n" << CLEAR;
		harl_test.complain("INFO");
		std::cout << RED << "\ninput \"info\"\n" << CLEAR;
		harl_test.complain("info");
		std::cout << GREEN << "\ninput \"WARNING\"\n" << CLEAR;
		harl_test.complain("WARNING");
		std::cout << RED << "\ninput \"warning\"\n" << CLEAR;
		harl_test.complain("warning");
		std::cout << GREEN << "\ninput \"ERROR\"\n" << CLEAR;
		harl_test.complain("ERROR");
		std::cout << RED << "\ninput \"error\"\n" << CLEAR;
		harl_test.complain("error");
		std::cout << RED << "\ninput \"WERROR\"\n" << CLEAR;
		harl_test.complain("WERROR");
		return (0);		
	}
	Harl	harl;
	harl.complain(av[1]);
	return (0);
}
