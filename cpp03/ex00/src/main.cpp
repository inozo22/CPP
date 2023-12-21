/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 11:40:03 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//At this moment, let with colour depends on the function.

int	main(void)
{
	std::cout << GREEN "\n>>>>>>>>>> MY TEST <<<<<<<<<<\n" CLEAR << std::endl;
	
	std::string Clap1Name = "S3-E3";
	std::string Clap2Name = "D-4QP";

	ClapTrap	Clap1(Clap1Name);
	ClapTrap	Clap2(Clap2Name);

	Clap1.beRepaired(0);
	Clap1.beRepaired(10);

    std::cout << GREEN "\n---Loop test with 10 times attack and takeDamage\n" CLEAR << std::endl;

	for (int i = 0; i < 10; i++) 
	{
		Clap1.attack(Clap2Name);
		Clap2.takeDamage(CLAPTRAP_DEFAULT_DAMAGE);
	}
    std::cout << GREEN "\n---Hello, after a loop!\n" CLEAR << std::endl;
	std::cout << "Clap1.attack(Clap2Name):" << std::endl;
	Clap1.attack(Clap2Name);
	std::cout << "\nClap2.takeDamage(5):" << std::endl;
	Clap2.takeDamage(5);
	std::cout << "\nClap2.beRepaired(4):" << std::endl;
	Clap2.beRepaired(4);
	std::cout << "\nClap2.attack(Clap1Name):" << std::endl;
	Clap2.attack(Clap1Name);
	std::cout << "\nClap1.takeDamage(5):" << std::endl;
	Clap1.takeDamage(5);
	std::cout << "\nClap1.beRepaired(5000):" << std::endl;
	Clap1.beRepaired(5000);
	std::cout << "\nClap2.beRepaired(5000):" << std::endl;
	Clap2.beRepaired(5000);
	std::cout << "\nClap2.attack(Clap2Name):" << std::endl;
	Clap2.attack(Clap2Name);
	std::cout << "\nClap2.takeDamage(5009):" << std::endl;
	Clap2.takeDamage(5009);
	std::cout << "\nClap2.beRepaired(5000):" << std::endl;
	Clap2.beRepaired(5000);
	std::cout << "\nClap2.attack(Clap1Name):" << std::endl;
	Clap2.attack(Clap1Name);
	std::cout << "\nClap2.takeDamage(1):" << std::endl;
	Clap2.takeDamage(1);
	return 0;
}
