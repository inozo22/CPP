/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:59:32 by nimai             #+#    #+#             */
/*   Updated: 2023/10/26 16:09:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//***	constructor and destructor//constructor and destructor	***//
DiamondTrap::DiamondTrap( void )
{
	std::cout << "Default constructor called in DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), FragTrap(name + "_flag_name"), ScavTrap(name + "_scav_name")
{
	this->_name = name;
	this->hp = FragTrap::max_hp;
	this->max_hp = FragTrap::max_hp;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << "DiamondTrap " << name << ": Created." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{	
	std::cout << this->name << ": Default destructor called in DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << this->name << ": Copy constructor called." << std::endl;
	this->operator=(src);
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &src )
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

void	DiamondTrap::whoAmI( void )
{
	if (this->hp > 0)
	{
		std::cout << CYAN"I am " << this->_name << " and my ClapTrap's name is " << ClapTrap::name << CLEAR << std::endl;
	}
	else
	{
		std::cout << "DiamondTrap " << this->name << " doesn't know who is he." << std::endl;
	}
	std::cout << GREEN << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

/**********************************************************************************/
