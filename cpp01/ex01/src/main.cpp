/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/07/28 15:27:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name;
	std::string number;
	int	N;

	std::cout << "\n...You are creating zombie horde\n";
	std::cout << "Zombie name > " << std::flush;
	std::cin >> name;
	std::cout << "How many zombies? > " << std::flush;
	std::cin >> number;

//　Having problem from here   
	N = std::to_integer(number);
	Zombie *zombies = zombieHorde(N, name);

	return 0;
}
