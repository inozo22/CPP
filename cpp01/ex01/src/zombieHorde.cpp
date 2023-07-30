/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:09:21 by nimai             #+#    #+#             */
/*   Updated: 2023/07/30 16:28:16 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];
//	char buffer[10];
//	std::string num;
//	std::ostringstream convert;

	for (int i = 0; i < N; ++i)
	{
		zombies[i].setName( name );
//		std::sprintf(buffer, "%d", i + 1);
//		std::string num(buffer);
//		num = std::to_string(i + 1);
//		name += num;
//		zombies = new Zombie( name );
	//	std::cout << name << i + 1 << std::endl;
//		zombies->announce();
	}
    return (zombies);
}
