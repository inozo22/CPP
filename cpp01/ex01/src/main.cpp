/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/07/30 16:32:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

int	main(void)
{
	std::string name;
//	std::string number;
	int	N;

	std::cout << "\n...You are creating zombie horde\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;
	std::cout << "How many zombies? > " << std::flush;
	std::cin >> N;

//　Having problem from here   
//	N = std::to_stoi(number);
	Zombie *zombies = zombieHorde(N, name);
//	std::cout << N << name << std::endl;
//	std::cout << zombies << std::endl;
	for (int i = 0; i < N; ++i)
	{
		zombies[i].announce();
	}
	delete[] (zombies);
	return 0;
}
