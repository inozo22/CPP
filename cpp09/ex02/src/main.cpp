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
	try
	{
//		PmergeMe test;
//		std::cout << "call constructor(`-´)/" << std::endl;
		PmergeMe pmerge(ac, av);

//		PmergeMe ref(pmerge);
//		test = pmerge;
//		std::cout << "call sortProcess(`*´)/" << std::endl;
//		ref.sortProcess();
//		test.sortProcess();
		pmerge.sortProcess();
//		std::cout << "call printResult\\(`3´)/" << std::endl;
		pmerge.printResult();
//		test.printResult();
//		ref.printResult();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}
