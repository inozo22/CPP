/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:09:21 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 09:43:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		std::string num = std::to_string(i + 1);
		zombies[i].setName( name + num );
	}
    return (zombies);
}
