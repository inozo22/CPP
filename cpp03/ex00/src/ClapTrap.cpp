/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/10/23 16:45:32 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//***	constructor and destructor//constructor and destructor	***//
ClapTrap::ClapTrap( void )
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{	
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
}
//***	constructor and destructor//constructor and destructor	***//

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


/**********************************************************************************/
void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name <<  " attacks " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << ", causing" << amount << " points of damage!" <<  " took damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name <<  " be repaired " << amount << " of points!" << std::endl;
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
