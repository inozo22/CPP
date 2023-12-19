/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:04:25 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 10:05:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( void )
{
	std::cout << "Default constructor called." << std::endl;
}

HumanB::HumanB( std::string input_name ) : name(input_name), weapon(NULL)
{
	std::cout << "HumanB, his/her name is " << name << std::endl;
}

HumanB::~HumanB(void)
{	
	std::cout << this->name << " has left from the field." << std::endl;
}

void	HumanB::attack( void )
{
	if (this->weapon == NULL)
		std::cout << this->name << " has attacked with his fist" << std::endl;	
	else
		std::cout << this->name << " has attacked with his " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &input_weapon )
{
	weapon = &input_weapon;
}
