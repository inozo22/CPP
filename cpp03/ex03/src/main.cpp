/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/10/26 16:00:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"
// #include "DiamondTrap.hpp"

// int	main(void)
// {
// 	// std::string clapName = "C000";
// 	// std::string scavName = "S001";
// 	// std::string fragName = "F002";

// 	// ScavTrap	scav(scavName);
// 	// FragTrap	frag(fragName);
// 	// ClapTrap	clap(clapName);

// 	// scav.beRepaired(0);
// 	// scav.beRepaired(10);
// 	// frag.beRepaired(10);
// 	// for (int i = 0; i < 5; i++) 
// 	// {
// 	// 	clap.attack(scavName);
// 	// 	scav.takeDamage(CLAPTRAP_DEFAULT_DAMAGE);
// 	// }
//     // std::cout << "Hello, after a loop!" << std::endl;
// 	// scav.attack(scavName);
// 	// clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
// 	// clap.beRepaired(4);
// 	// scav.guardGate();
// 	// clap.attack(clapName);
// 	// scav.takeDamage(5);
// 	// scav.beRepaired(5000);
// 	// clap.beRepaired(5000);
// 	// clap.attack(scavName);
// 	// clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
// 	// clap.beRepaired(5000);
// 	// clap.attack(clapName);
// 	// clap.takeDamage(1);
// 	// frag.attack(scavName);
// 	// scav.takeDamage(FRAGTRAP_DEFAULT_DAMAGE);
// 	// frag.highFiveGuys();


	
//     // DiamondTrap diamond("Diamond");

//     // diamond.whoAmI();
//     // diamond.attack("Target");
//     // diamond.FragTrap::attack("Target");
//     // diamond.ScavTrap::attack("Target");
// 	// return 0;
// }

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>



int	main(void) {
	std::string diamondTrapName = "D003";
	std::string scavTrapName = "S001";
	std::string clapTrapName = "C000";

	DiamondTrap	diamondTrap(diamondTrapName);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	diamondTrap.whoAmI();
	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(clapTrap.getDamage());
	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(scavTrap.getDamage());
	diamondTrap.attack(scavTrapName);
	scavTrap.takeDamage(diamondTrap.getDamage());
	diamondTrap.highFiveGuys();
	diamondTrap.guardGate();
	diamondTrap.takeDamage(5000);
	diamondTrap.beRepaired(5000);
	diamondTrap.whoAmI();
	return (0);
}
