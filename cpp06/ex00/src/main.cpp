/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:01:57 by nimai             #+#    #+#             */
/*   Updated: 2024/03/01 09:35:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
//	ScalarConverter test;
	std::string str(av[1]);
	if (ac != 2)
	{
		std::cout << "USAGE: ./conver <number>" << std::endl;
		return (1);
	}
	try
	{
//		test.convert(str);
		std::cout << GREEN "Converting... [ " << str << " ]" RESET << std::endl;
		ScalarConverter::convert(str);
	}
	catch(const std::exception & e)
	{
		std::cout << RED "" << e.what() << RESET << std::endl;
	}
    return (0);
}

