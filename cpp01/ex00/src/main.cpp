/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 09:07:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::string name1;

	std::cout << "\n...You are creating zombie on the stack\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name1;

	Zombie zombie1(name1);
	zombie1.announce();

	std::string name2;

	std::cout << "\n...You are creating zombie on the heap\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name2;

	Zombie *zombie2 = newZombie(name2);
	zombie2->announce();

	std::string name3;

	std::cout << "\nExcute randomChump." << std::endl;
	std::cout << "...You are creating zombie on the stack\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name3;
	randomChump(name3);
	
	std::cout << "\n...Deleting " << name2;
	delete zombie2;
	return 0;
}
