/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 13:45:52 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
ClapTrap::ClapTrap( void ) : hp(CLAPTRAP_DEFAULT_HP), energy(CLAPTRAP_DEFAULT_ENERGY), damage(CLAPTRAP_DEFAULT_DAMAGE), max_hp(CLAPTRAP_DEFAULT_HP)
{
	this->name = "noname";
	std::cout << "ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hp(CLAPTRAP_DEFAULT_HP), energy(CLAPTRAP_DEFAULT_ENERGY), damage(CLAPTRAP_DEFAULT_DAMAGE), max_hp(CLAPTRAP_DEFAULT_HP)
{
	std::cout << "ClapTrap " << this->name << ": Created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
	std::cout << this->name << ": Destructor called in ClapTrap." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << this->name << ": Copy constructor called in ClapTrap." << std::endl;
	this->operator=(src);
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src )
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &src)//it's not neecessary? Cause I cannot compile when I have the same this and src
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
void	ClapTrap::attack(const std::string& target)
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << "ClapTrap " CYAN << this->name <<  CLEAR " attacks " << target << ", causing "
		<< this->damage << " points of damage!: " CLEAR;
		this->energy--;
	}
	else
	{
		std::cout << "ClapTrap " CYAN << this->name <<  CLEAR " can't attack due to lack of energy or hit points.: ";
	}
	std::cout << this->name << ": hp: " << this->hp << "/" << this->max_hp << " energy: " << this->energy << CLEAR << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " YELLOW << this->name << CLEAR " can't be taken more damage. It's already...: ";
	}
	else if (((int)this->hp - (int)amount) <= 0)
	{
		std::cout << "ClapTrap " YELLOW << this->name << CLEAR " takes " << amount - this->hp << " points of damage!: ";
		std::cout << RED << this->name << " is destroyed..." CLEAR << ": ";
		this->hp = 0;
	}
	else
	{
		std::cout << "ClapTrap " YELLOW << this->name << CLEAR " takes " << amount << " points of damage!: ";
		this->hp -= amount;
	}
	std::cout << this->name << ": hp: " << this->hp << "/" << this->max_hp << " energy: " << this->energy << CLEAR << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hp > 0 && this->energy > 0)
	{
		if (((int)this->hp + (int)amount) > (int)this->max_hp)
		{
			amount = (int)this->max_hp - (int)this->hp;
			this->hp = this->max_hp;
		}
		else
		{
			this->hp += amount;		
		}
        std::cout << "ClapTrap " BLUE << this->name << CLEAR << " is being repaired for " << amount << " hit points.";
        this->energy--;
    }
	else if (this->hp <= 0)
        std::cout << "ClapTrap " BLUE << this->name << CLEAR " can't be repaired due to be severely damaged.: ";
	else
        std::cout << "ClapTrap " BLUE << this->name << CLEAR " can't be repaired due to lack of energy points.: ";	
	std::cout << this->name << ": hp: " << this->hp << "/" << this->max_hp << " energy: " << this->energy << CLEAR << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->name);
}
unsigned int	ClapTrap::getHp(void) const
{
	return (this->hp);	
}
unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->energy);
}
unsigned int	ClapTrap::getDamage(void) const
{
	return (this->damage);
}
unsigned int	ClapTrap::getMaxHp(void) const
{
	return (this->max_hp);
}



/**********************************************************************************/
