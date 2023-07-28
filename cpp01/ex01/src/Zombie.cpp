/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:45 by nimai             #+#    #+#             */
/*   Updated: 2023/07/28 12:06:53 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << this->name << " has been awaken." << std::endl;
}

Zombie::~Zombie(void)
{	
	std::cout << std::endl << this->name << " has been destroyed." << std::endl;
}

void	Zombie::announce( void )
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
