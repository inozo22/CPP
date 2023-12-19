/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 09:43:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	std::string name;
	int	N;

	std::cout << "\n...You are creating zombie horde\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;
	std::cout << "How many zombies in the horde? > " << std::flush;
	std::cin >> N;

	Zombie *zombies = zombieHorde(N, name);
	for (int i = 0; i < N; ++i)
	{
		zombies[i].announce();
	}
	delete[] (zombies);
	return 0;
}
