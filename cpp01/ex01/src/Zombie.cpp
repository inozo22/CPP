/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:45 by nimai             #+#    #+#             */
/*   Updated: 2023/07/30 16:35:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "... creating a zombie..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << this->name << " has been awaken." << std::endl;
}

Zombie::~Zombie(void)
{	
	std::cout << std::endl << this->name << " has returned to its grave." << std::endl;
}

void	Zombie::announce( void )
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}
