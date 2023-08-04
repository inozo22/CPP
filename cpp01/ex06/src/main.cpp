/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/08/04 17:05:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "you have to put for arguments as \"./Harl s1\"" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(av[1]);
	return (0);
}

/**
 * @note 230804nimai: all argument should be UPPER CASE at this moment. Confirmation required before submit.
  */
