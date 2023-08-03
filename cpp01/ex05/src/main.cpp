/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/08/03 13:45:13 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "you have to put for arguments as \"./replace <filename> s1 s2\"" << std::endl;
		//std::exit(1);
		return (1);
	}



	return (std::cout << "made it" << std::endl, 0);
	
}
