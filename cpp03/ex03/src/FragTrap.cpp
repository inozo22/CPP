/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:45:42 by nimai             #+#    #+#             */
/*   Updated: 2023/10/26 11:32:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//***	constructor and destructor//constructor and destructor	***//
FragTrap::FragTrap( void )
{
	std::cout << "Default constructor called." << std::endl;
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
	std::cout << this->name << ": Default destructor called in FragTrap." << std::endl;
}

FragTrap::FragTrap( const FragTrap &src )
{
	std::cout << this->name << ": Copy constructor called." << std::endl;
	this->operator=(src);
}

FragTrap &FragTrap::operator=( const FragTrap &src )
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
// void	FragTrap::attack(const std::string& target)
// {
// 	if (this->hp > 0 && energy > 0)
// 	{
// 		std::cout << "FragTrap " << this->name <<  " attacks " << target << ", causing "
// 		<< this->damage << "points of damage!" << std::endl;
// 		this->energy--;
// 	}
// 	else
// 	{
// 		std::cout << "FragTrap " << this->name << " can't attack due to lack of energy or hit points." << std::endl;
// 	}
// 	std::cout << GREEN << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
// }

void	FragTrap::highFiveGuys( void )
{
	if (this->hp > 0 && energy > 0)
	{
		std::cout << CYAN"FragTrap " << this->name <<  " looks for someone to high-five." << CLEAR << std::endl;
		this->energy--;
	}
	else
	{
		std::cout << "FragTrap " << this->name << " can't move to find its friend due to lack of energy or hit points." << std::endl;
	}
	std::cout << GREEN << this->name << ": hp: " << this->hp << " energy: " << this->energy << CLEAR << std::endl;
}

/**********************************************************************************/
