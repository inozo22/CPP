/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:59:32 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 17:47:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->hp = FragTrap::max_hp;
	this->max_hp = FragTrap::max_hp;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << "DiamondTrap " << this->_name << ": Created." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{	
	std::cout << this->_name << ": Destructor called in DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src )
{
	this->_name = src.getName();
	std::cout << this->_name << ": Copy constructor called in DiamondTrap." << std::endl;
	this->operator=(src);
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &src )
{
	std::cout << "Copy assignment operator called in DiamondTrap." << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->hp = src.getHp();
		this->energy = src.getEnergy();
		this->damage = src.getDamage();
		this->max_hp = src.getMaxHp();
		ClapTrap::name = src.getClapTrapName();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/

void	DiamondTrap::whoAmI( void )
{
	if (this->hp > 0)
	{
		std::cout << "I am " LGREEN << this->_name << CLEAR " and my ClapTrap's name is " ORANGE << ClapTrap::name << ": ";
	}
	else
	{
		std::cout << "DiamondTrap " LGREEN << this->_name << CLEAR " doesn't know who is he.: ";
	}
	std::cout << this->_name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

std::string	DiamondTrap::getName( void ) const
{
	return (this->_name);
}

std::string	DiamondTrap::getClapTrapName( void ) const
{
	return (ClapTrap::name);
}
/**********************************************************************************/

std::ostream&	operator<<(std::ostream &out, DiamondTrap const &src)
{
	out << "DiamondTrap name: " << src.getName() << "\nClapTrap name: " << src.getClapTrapName()
	<< "\nhp: " << src.getHp() << "\nenergy: " << src.getEnergy() << "\ndamage: " 
	<< src.getDamage() << "\nmax hp: " << src.getMaxHp() << "\n";
	return (out);
}

