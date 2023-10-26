/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/10/26 10:21:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::string clapName = "C000";
	std::string scavName = "S001";
	std::string fragName = "F002";

	ScavTrap	scav(scavName);
	FragTrap	frag(fragName);
	ClapTrap	clap(clapName);

	scav.beRepaired(0);
	scav.beRepaired(10);
	frag.beRepaired(10);
	for (int i = 0; i < 5; i++) 
	{
		clap.attack(scavName);
		scav.takeDamage(CLAPTRAP_DEFAULT_DAMAGE);
	}
    std::cout << "Hello, after a loop!" << std::endl;
	scav.attack(scavName);
	clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	clap.beRepaired(4);
	scav.guardGate();
	clap.attack(clapName);
	scav.takeDamage(5);
	scav.beRepaired(5000);
	clap.beRepaired(5000);
	clap.attack(scavName);
	clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	clap.beRepaired(5000);
	clap.attack(clapName);
	clap.takeDamage(1);
	frag.attack(scavName);
	scav.takeDamage(FRAGTRAP_DEFAULT_DAMAGE);
	frag.highFiveGuys();
	return 0;
}
