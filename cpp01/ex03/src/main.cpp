/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 10:15:45 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iomanip>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( void )
{
	std::cout << GREEN "\n<<<<<<<<<< MY TEST >>>>>>>>>>" CLEAR << std::endl;
	{
		std::cout << BLUE "\nHUMAN A" CLEAR << std::endl;

		Weapon club = Weapon("crude spiked club");
		HumanA bob ("Bob", club);
		
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << BLUE "\nHUMAN B" CLEAR << std::endl;
		HumanB jim("Jim");
		jim.attack();
	
		Weapon club = Weapon("crude spiked club");
		
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}

// int	main( void )
// {
// 	std::cout << GREEN "\n<<<<<<<<<< SUBJECT TEST >>>>>>>>>>" CLEAR << std::endl;
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club"); jim.attack();
// 	}
// 	return 0;
// }
