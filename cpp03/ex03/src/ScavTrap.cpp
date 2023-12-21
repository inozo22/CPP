/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 16:29:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->hp = SCAVTRAP_DEFAULT_HP;
	this->max_hp = SCAVTRAP_DEFAULT_HP;
	this->energy = SCAVTRAP_DEFAULT_ENERGY;
	this->damage = SCAVTRAP_DEFAULT_DAMAGE;
	std::cout << "ScavTrap " << name << ": Created." << std::endl;
}

ScavTrap::~ScavTrap(void)
{	
	std::cout << this->name << ": Destructor called in ScavTrap." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src )
{
	std::cout << this->name << ": Copy constructor called in ScavTrap." << std::endl;
	this->operator=(src);
}

ScavTrap &ScavTrap::operator=( const ScavTrap &src )
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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
void	ScavTrap::attack(const std::string& target)
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << "ScavTrap " CYAN << this->name << CLEAR " attacks " << target << ", causing "
		<< this->damage << " points of damage!: ";
		this->energy--;
	}
	else
	{
		std::cout << "ScavTrap " CYAN << this->name << CLEAR " can't attack due to lack of energy or hit points.: ";
	}
	std::cout << this->name << ": hp: " << this->hp << "/" << this->max_hp << " energy: " << this->energy << CLEAR << std::endl;
	// std::cout << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

void	ScavTrap::guardGate( void )
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << "ScavTrap " CYAN << this->name << CLEAR " is now in Gate keeper mode.: ";
		this->energy--;
	}
	else
	{
		std::cout << "ScavTrap " CYAN << this->name << CLEAR " can't switch to Gate keeper mode due to lack of energy or hit points.: ";
	}
	std::cout << this->name << ": hp: " << this->hp << "/" << this->max_hp << " energy: " << this->energy << CLEAR << std::endl;
	// std::cout << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

/**********************************************************************************/
