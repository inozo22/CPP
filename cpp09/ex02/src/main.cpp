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
		PmergeMe pmerge(ac, av);
		pmerge.sortProcess();
		pmerge.printResult();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}
