/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:09:21 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 11:51:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <sstream>

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		std::ostringstream temp;
		temp << (i + 1);
		zombies[i].setName( name + temp.str() );
	}
    return (zombies);
}
