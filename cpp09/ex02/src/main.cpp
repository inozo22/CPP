/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:18 by nimai             #+#    #+#             */
/*   Updated: 2024/03/11 08:06:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main( int ac, char *av[] )
{
//	if (ac < 2)
//	{
//		std::cout << "USAGE: " << av[0] << " <positive integer sequence>" << std::endl;
//		return (1);
//	}
	try
	{
		std::cout << "call constructor(`-´)/" << std::endl;
		PmergeMe pmerge(ac, av);
		std::cout << "call sortProcess(`*´)/" << std::endl;
		pmerge.sortProcess();
		std::cout << "call printResult\\(`3´)/" << std::endl;
		pmerge.printResult();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}
