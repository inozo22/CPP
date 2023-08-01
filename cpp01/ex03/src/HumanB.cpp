/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:04:25 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 16:21:16 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string input_name ) : name(input_name)
{
	std::cout << "HumanB, his/her name is " << name << std::endl;
}

HumanB::~HumanB(void)
{	
	std::cout << this->name << " has left from the field." << std::endl;
}

void	HumanB::attack( void )
{
	std::cout << this->name << " has attacked with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &input_weapon )
{
	weapon = &input_weapon;
}
