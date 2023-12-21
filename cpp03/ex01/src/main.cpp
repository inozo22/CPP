/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 13:48:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int	main(void)
{
	std::cout << GREEN "\n>>>>>>>>>> MY TEST <<<<<<<<<<\n" CLEAR << std::endl;

	std::string clapName = "Clap";
	std::string scavName = "Scav";

	ScavTrap	scav(scavName);
	ClapTrap	clap(clapName);

	scav.beRepaired(0);
	scav.beRepaired(10);

    std::cout << GREEN "\n---Loop test with 10 times Clap attacks and Scav takeDamages\n" CLEAR << std::endl;

	for (int i = 0; i < 5; i++) 
	{
		clap.attack(scavName);
		scav.takeDamage(CLAPTRAP_DEFAULT_DAMAGE);
	}

    std::cout << GREEN "\n---Loop test with 10 times Scav attacks and Clap takeDamages\n" CLEAR << std::endl;
	for (int i = 0; i < 5; i++) 
	{
		scav.attack(clapName);
		clap.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	}

	std::cout << GREEN "\n---Hello, after a loop!\n" CLEAR << std::endl;

	ClapTrap	cava;
	cava = clap;
	scav.attack("Cava");
	std::cout << BLUE "\nCheck if the coppy constructor works. It will be a copy of Clap ⬇" CLEAR << std::endl;
	cava.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);

	std::cout << BLUE "\nAnother ScavTrap, NewEnemy has been showed." CLEAR << std::endl;

	std::string	newOneName("NewEnemy");
	ScavTrap	newOne(newOneName);

	scav.attack(newOneName);
	newOne.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	newOne.beRepaired(4);
	newOne.guardGate();
	newOne.attack(scavName);
	scav.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	scav.beRepaired(5000);
	clap.beRepaired(5000);
	clap.attack(scavName);
	newOne.attack(clapName);
	
	std::cout << BLUE "\nNew enemy starts endless guard gate mode!" CLEAR << std::endl;
	for (int i = 0; i < 50; i++)
		newOne.guardGate();	
	return 0;
}


