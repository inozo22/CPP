/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:01:57 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 10:56:35 by nimai            ###   ########.fr       */
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
		std::cout << "Converting... [ " << av[1] << " ]" << std::endl;
		ScalarConverter test(av[1]);
		std::cout << test << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << RED "" << e.what() << RESET << std::endl;
	}
    return (0);
}

