/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/07/31 17:17:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


/* int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << std::left << std::setw(32) << "string memory address: " << &string << "\n";
	std::cout << std::left << std::setw(32) << "stringPTR memory address: " << stringPTR << "\n";
	std::cout << std::left << std::setw(32) << "stringREF memory address: " << &stringREF << std::endl;

	std::cout << std::left << std::setw(32) << "string value: " << string << "\n";
	std::cout << std::left << std::setw(32) << "stringPTR value: " << *stringPTR << "\n";
	std::cout << std::left << std::setw(32) << "stringREF value: " << stringREF << std::endl;
	return 0;
} */

int	main( void )
{
	{
		Weapon club = Weapon("crude spiked club");
		
		
		HumanA bob ("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
