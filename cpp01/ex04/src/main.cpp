/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 16:55:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include "Replace.hpp"


int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "you have to put for arguments as \"./replace <filename> s1 s2\"" << std::endl;
		std::exit(1);
	}
	std::ifstream ifs(av[1]);
	if (!ifs)
	{
		std::cerr << "failed open file." << std::endl;
		std::exit(1);
	}
	std::string buf;
	ifs >> buf;
	if (!ifs)
	{
		std::cerr << "failed read file." << std::endl;
		std::exit(1);
	}
	while (ifs)
	{
		std::cout << buf << std::endl;
		ifs >> buf;		
	}
	std::cout << "over the file." << std::endl;
	return (0);
	
}


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

/* int	main( void )
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
} */
