/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/10/24 18:14:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//***	constructor and destructor//constructor and destructor	***//
ClapTrap::ClapTrap( void ) : _hp(defaultHp), _energy(defaultEnergy), _damage(defaultDamage)
{
	this->_name = "noname";
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(defaultHp), _energy(defaultEnergy), _damage(defaultDamage)
{
	std::cout << "ClapTrap, his/her name is " << name << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
	std::cout << this->_name << ": Default destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
}

ClapTrap &ClapTrap::operator=( const ClapTrap &src )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
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
		std::cout << "ClapTrap " << this->_name <<  " attacks " << target << ", causing "
		<< this->_damage << "points of damage!" << std::endl;
		this->_energy--;
	}
	else
	{
		std::cout << this->_name << " can't attack due to lack of energy or hit points." << std::endl;
	}	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
        this->_hp -= amount;
	}
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " is destroyed..." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hp > 0 && this->_energy > 0)
	{
        std::cout << this->_name << " is being repaired for " << amount << " hit points." << std::endl;
        this->_hp += amount;
        this->_energy--;
    }
	else if (this->_hp <= 0)
	{
        std::cout << _name << " can't be repaired due to be severely damaged." << std::endl;
    }
	else
        std::cout << _name << " can't be repaired due to lack of energy points." << std::endl;	
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
