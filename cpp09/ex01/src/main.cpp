/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:01:18 by nimai             #+#    #+#             */
/*   Updated: 2024/03/11 08:02:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main( int ac, char *av[] )
{
	if (ac != 2)
	{
		std::cerr << "USAGE: " << av[0] << "\"RPN expression\">" << std::endl;
		return (1);
	}
	std::string input = av[1];
	RPN rpn(input);
	int result = rpn.evaluate();
	std::cout << result << std::endl;
	return (0);
}
