/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 15:39:11 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::string clapName = "C000";
	std::string scavName1 = "S001";
	std::string scavName2 = "S004";
	std::string fragName1 = "F002";
	std::string fragName2 = "F003";

	ClapTrap	clap(clapName);
	ScavTrap	scav1(scavName1);
	FragTrap	frag1(fragName1);

	std::cout << GREEN "\n>>>>>>>>>> MY TEST <<<<<<<<<<\n" CLEAR << std::endl;

	std::cout << BLUE "\n---Check beRepaired function." CLEAR << std::endl;
	scav1.beRepaired(0);
	scav1.beRepaired(10);
	frag1.beRepaired(10);
	clap.beRepaired(10);
	
	std::cout << BLUE "\n---Loop " << scavName1 << " atacks 5 times " << fragName1 << "." CLEAR << std::endl;
	for (int i = 0; i < 5; i++) 
	{
		scav1.attack(fragName1);
		frag1.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	}

	std::cout << BLUE "\n---F002 is scrap now, we will prepare F003." CLEAR << std::endl;
	FragTrap	frag2(fragName2);


	std::cout << BLUE "\n---Loop " << fragName2 << " atacks 5 times " << scavName1 << "." CLEAR << std::endl;
	for (int i = 0; i < 5; i++) 
	{
		frag2.attack(scavName1);
		scav1.takeDamage(FRAGTRAP_DEFAULT_DAMAGE);
	}
	std::cout << BLUE "\n---S001 is scrap now, we will prepare S004." CLEAR << std::endl;
	ScavTrap	scav2(scavName2);



	std::cout << BLUE "\n---Hello, after a loop!\n" CLEAR << std::endl;

	frag2.highFiveGuys();
	scav2.attack(fragName2);
	frag2.takeDamage(SCAVTRAP_DEFAULT_DAMAGE);
	frag2.beRepaired(5000);
	frag2.beRepaired(5000);
	clap.attack(fragName2);
	frag2.attack(scavName2);
	scav2.takeDamage(FRAGTRAP_DEFAULT_DAMAGE);

	std::cout << BLUE "\n---F002 starts greeting to all over the world👋 100 times..." CLEAR << std::endl;
	for (int i = 0; i < 100; i++)
		frag2.highFiveGuys();
	return 0;
}
