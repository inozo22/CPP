/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/10/25 14:03:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::string clapName = "Clap";
	std::string scavName = "Scav";

	ScavTrap	scav(scavName);
	ClapTrap	clap(clapName);

	scav.beRepaired(0);
	scav.beRepaired(10);
	for (int i = 0; i < 10; i++) 
	{
		scav.attack(clapName);
		clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	}
    std::cout << "Hello, after a loop!" << std::endl;
	scav.attack(scavName);
	clap.takeDamage(5);
	clap.beRepaired(4);
	clap.attack(clapName);
	scav.takeDamage(5);
	scav.beRepaired(5000);
	clap.beRepaired(5000);
	clap.attack(scavName);
	clap.takeDamage(5009);
	clap.beRepaired(5000);
	clap.attack(clapName);
	clap.takeDamage(1);
	return 0;
}


