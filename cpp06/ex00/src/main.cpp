/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:01:57 by nimai             #+#    #+#             */
/*   Updated: 2024/02/27 15:55:14 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "USAGE: ./conver <number>" << std::endl;
		return (1);
	}
	try
	{
		std::cout << GREEN "Converting... [ " << av[1] << " ]" RESET << std::endl;
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception & e)
	{
		std::cout << RED "" << e.what() << RESET << std::endl;
	}
    return (0);
}

