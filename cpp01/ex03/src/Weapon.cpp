/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:11 by nimai             #+#    #+#             */
/*   Updated: 2023/08/01 16:22:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string name_type )
{
	std::cout << "\n...preparing for the battle." << std::endl;
	this->type = name_type;
}

Weapon::~Weapon( void )
{	
	std::cout << this->type << " has been destroyed." << std::endl;
}

std::string	Weapon::getType( void )
{
	return (type);
}

void	Weapon::setType( std::string name_type )
{
	this->type = name_type;
}