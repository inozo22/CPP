/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:45:42 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 15:36:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
FragTrap::FragTrap( void )
{
	std::cout << "FlagTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->hp = FRAGTRAP_DEFAULT_HP;
	this->max_hp = FRAGTRAP_DEFAULT_HP;
	this->energy = FRAGTRAP_DEFAULT_ENERGY;
	this->damage = FRAGTRAP_DEFAULT_DAMAGE;
	std::cout << "FragTrap " << name << ": Created." << std::endl;
}

FragTrap::~FragTrap(void)
{	
	std::cout << this->name << ": Destructor called in FragTrap." << std::endl;
}

FragTrap::FragTrap( const FragTrap &src )
{
	std::cout << this->name << ": Copy constructor called in FragTrap." << std::endl;
	this->operator=(src);
}

FragTrap &FragTrap::operator=( const FragTrap &src )
{
	std::cout << "Copy assignment operator called in FragTrap." << std::endl;
	if (this != &src)
	{
		this->name = src.getName();
		this->hp = src.getHp();
		this->energy = src.getEnergy();
		this->damage = src.getDamage();
		this->max_hp = src.getMaxHp();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/

void	FragTrap::highFiveGuys( void )
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << "FragTrap " MAGENTA << this->name << CLEAR " looks for someone to high-five... HIGH-FIVE!!!!: ";
		this->energy--;
	}
	else
	{
		std::cout << "FragTrap " MAGENTA << this->name << CLEAR " can't move to find its friend due to lack of energy or hit points.: ";
	}
	std::cout << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

/**********************************************************************************/
