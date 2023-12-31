/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/10/30 12:53:04 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//***	constructor and destructor//constructor and destructor	***//
ClapTrap::ClapTrap( void ) : hp(CLAPTRAP_DEFAULT_HP), max_hp(CLAPTRAP_DEFAULT_HP), energy(CLAPTRAP_DEFAULT_ENERGY), damage(CLAPTRAP_DEFAULT_DAMAGE)
{
	this->name = "noname";
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hp(CLAPTRAP_DEFAULT_HP), max_hp(CLAPTRAP_DEFAULT_HP), energy(CLAPTRAP_DEFAULT_ENERGY), damage(CLAPTRAP_DEFAULT_DAMAGE)
{
	std::cout << this->name << ": Created in ClapTrap." << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
	std::cout << this->name << ": Default destructor called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << this->name << ": Copy constructor called." << std::endl;
	this->operator=(src);
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->name = src.getName();
		this->hp = src.getHp();
		this->energy = src.getEnergy();
		this->damage = src.getDamage();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	ClapTrap::attack(const std::string& target)
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << "ClapTrap " << this->name <<  " attacks " << target << ", causing "
		<< this->damage << " points of damage!";
		this->energy--;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " can't attack due to lack of energy or hit points.";
	}
	std::cout << "[HP]" << this->hp << "/ " << this->max_hp << std::endl;
	std::cout << GREEN << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " can't be taken more damage. It's already...";
	}
	else if (((int)this->hp - (int)amount) <= 0)
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount - this->hp << " points of damage!" << std::endl;
		std::cout << this->name << " is destroyed...";
		this->hp = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!";
	}
	if ((int)this->hp < ((int)this->max_hp * 0.5))
		std::cout << RED << "[HP]" << this->hp << "/" << this->max_hp << CLEAR << std::endl;
	else
		std::cout << YELLOW << "[HP]" << this->hp << "/" << this->max_hp << CLEAR << std::endl;
	std::cout << RED << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;

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
        std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << " hit points.";
        this->energy--;
    }
	else if (this->hp <= 0)
	{
        std::cout << "ClapTrap " << name << " can't be repaired due to be severely damaged.";
    }
	else
        std::cout << "ClapTrap " << name << " can't be repaired due to lack of energy points.";	
	if ((int)this->hp < ((int)this->max_hp * 0.5))
		std::cout << RED << "[HP]" << this->hp << "/" << this->max_hp << CLEAR << std::endl;
	else
		std::cout << YELLOW << "[HP]" << this->hp << "/" << this->max_hp << CLEAR << std::endl;
	std::cout << BLUE << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
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



/**********************************************************************************/
