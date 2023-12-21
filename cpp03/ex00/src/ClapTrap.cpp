/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 11:34:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
ClapTrap::ClapTrap( void ) : _hp(CLAPTRAP_DEFAULT_HP), _energy(CLAPTRAP_DEFAULT_ENERGY), _damage(CLAPTRAP_DEFAULT_DAMAGE)
{
	this->_name = "noname";
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(CLAPTRAP_DEFAULT_HP), _energy(CLAPTRAP_DEFAULT_ENERGY), _damage(CLAPTRAP_DEFAULT_DAMAGE)
{
	std::cout << this->_name << ": Created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
	std::cout << this->_name << ": Destructor called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << this->_name << ": Copy constructor called." << std::endl;
	this->operator=(src);
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)//it's not neecessary? Cause I cannot compile when I have the same this and src
	{
		this->_name = src.getName();
		this->_hp = src.getHp();
		this->_energy = src.getEnergy();
		this->_damage = src.getDamage();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && _energy > 0)
	{
		std::cout << "ClapTrap " CYAN << this->_name <<  CLEAR " attacks " << target << ", causing "
		<< this->_damage << " points of damage!: " CLEAR;
		this->_energy--;
	}
	else
	{
		std::cout << "ClapTrap " CYAN << this->_name <<  CLEAR " can't attack due to lack of energy or hit points.: ";
	}
	std::cout << this->_name << ": hp: " << this->_hp << " energy: " << this->_energy << CLEAR << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " YELLOW << this->_name << CLEAR " can't be taken more damage. It's already...: ";
	}
	else
	{
		std::cout << "ClapTrap " YELLOW << this->_name << CLEAR " takes " << amount << " points of damage!: " CLEAR;
        this->_hp -= amount;
		if (this->_hp <= 0)
			std::cout << "ClapTrap " << this->_name << " is destroyed...: ";
	}
	std::cout << this->_name << ": hp: " << this->_hp << " energy: " << this->_energy << CLEAR << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hp > 0 && this->_energy > 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << CLEAR " is being repaired for " << amount << " hit points.: " CLEAR;
        this->_hp += amount;
        this->_energy--;
    }
	else if (this->_hp <= 0)
        std::cout << "ClapTrap " BLUE << this->_name << CLEAR " can't be repaired due to be severely damaged.: ";
	else
        std::cout << "ClapTrap " BLUE << this->_name << CLEAR " can't be repaired due to lack of energy points.: ";	
	std::cout << this->_name << ": hp: " << this->_hp << " energy: " << this->_energy << CLEAR << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}
unsigned int	ClapTrap::getHp(void) const
{
	return (this->_hp);	
}
unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}
unsigned int	ClapTrap::getDamage(void) const
{
	return (this->_damage);
}



/**********************************************************************************/
