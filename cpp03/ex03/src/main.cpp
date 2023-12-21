/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 17:46:41 by nimai            ###   ########.fr       */
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



int	main(void) 
{
	std::cout << GREEN "\n>>>>>>>>>> MY TEST <<<<<<<<<<\n" CLEAR << std::endl;

	std::string diamondTrapName1 = "D003";
	std::string diamondTrapName2 = "D800";
	std::string diamondTrapName3 = "DDDD";
	std::string scavTrapName = "S001";
	std::string clapTrapName = "C000";

	DiamondTrap	diamondTrap1(diamondTrapName1);
	DiamondTrap	diamondTrap2(diamondTrapName2);
	// DiamondTrap	diamondTrap3(diamondTrapName3);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);
	
	std::cout << BLUE "\n---Check first DiamondTrap. D003 and D800" CLEAR << std::endl;
	std::cout << "diamondTrap1: " << diamondTrap1 << std::endl;
	std::cout << "diamondTrap2: " << diamondTrap2 << std::endl << std::endl;
	
	diamondTrap1 = diamondTrap2;

	std::cout << BLUE "\n---Check after copy assignment operator called in DiamondTrap. D003 and D800" CLEAR << std::endl;
	std::cout << "diamondTrap1: " << diamondTrap1 << std::endl;
	std::cout << "diamondTrap2: " << diamondTrap2 << std::endl << std::endl;

	DiamondTrap diamondTrap3(diamondTrap1);

	std::cout << BLUE "\n---Check after copy constructor \"DiamondTrap diamondTrap3(diamondTrap1)\" called in DiamondTrap. D003 and D800" CLEAR << std::endl;
	std::cout << "diamondTrap1: " << diamondTrap1 << std::endl;
	std::cout << "diamondTrap3: " << diamondTrap3 << std::endl << std::endl;

	

	diamondTrap1.whoAmI();
	for (int i = 0; i < 5; ++i)
	{
		diamondTrap1.attack(diamondTrapName2);
		diamondTrap2.takeDamage(diamondTrap1.getDamage());
	}
	for (int i = 0; i < 50; ++i)
	{
		diamondTrap1.highFiveGuys();
		diamondTrap3.guardGate();
	}
	diamondTrap3.highFiveGuys();
	diamondTrap3.guardGate();
	diamondTrap3.takeDamage(5000);
	diamondTrap3.beRepaired(5000);
	diamondTrap3.whoAmI();
	return (0);
}
