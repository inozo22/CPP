/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/07/28 12:06:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name;

	std::cout << "\n...You are creating zombie on the stack\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;

	Zombie zombie1(name);
	zombie1.announce();

	std::cout << "\n...You are creating zombie on the heap\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;

	Zombie *zombie2 = newZombie(name);
	zombie2->announce();
	std::cout << "deleting " << name << std::endl;
	delete zombie2;

	std::cout << "\nExcute randomChump." << std::endl;
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;
	randomChump(name);
	return 0;
}
