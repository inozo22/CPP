/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 12:36:22 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
# include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "You have to put for arguments as \"./harlFilter s1\"" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(av[1]);
	return (0);
}
