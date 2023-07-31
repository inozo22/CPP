/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/07/31 17:17:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string input_name, Weapon &input_weapon ) : name(input_name), weapon(input_weapon)
{
	std::cout << "HumanA, his/her name is " << name << std::endl;
}

HumanA::~HumanA(void)
{	
	std::cout << std::endl << this->name << " has left from the field." << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
