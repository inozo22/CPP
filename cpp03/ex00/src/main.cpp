/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/10/24 18:16:17 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string Clap1Name = "S3-E3";
	std::string Clap2Name = "D-4QP";

	ClapTrap	Clap1(Clap1Name);
	ClapTrap	Clap2(Clap2Name);

	Clap1.beRepaired(0);
	Clap1.beRepaired(10);
	for (int i = 0; i < 10; i++) 
	{
		Clap1.attack(Clap2Name);
		Clap2.takeDamage(ClapTrap::defaultDamage);
	}
    std::cout << "Hello, after a loop!" << std::endl;
	Clap1.attack(Clap2Name);
	Clap2.takeDamage(5);
	Clap2.beRepaired(4);
	Clap2.attack(Clap1Name);
	Clap1.takeDamage(5);
	Clap1.beRepaired(5000);
	Clap2.beRepaired(5000);
	Clap2.attack(Clap2Name);
	Clap2.takeDamage(5000);
	Clap2.beRepaired(5000);
	Clap2.takeDamage(1);
	return 0;
}


