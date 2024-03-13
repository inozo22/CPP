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
	if (ac == 1)
	{
		std::cout << "USAGE: " << av[0] << " <positive integer sequence>" std::endl;
		return (1);
	}
	PmergeMe pmerge(ac, av);
	try
	{
		pmerge.process();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << "\n";
		exit (1);
	}
	return (0);
}
