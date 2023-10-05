/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/10/05 17:31:35 by nimai            ###   ########.fr       */
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
	std::cout << "Destructor called" << std::endl;
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
	if (this == &src)
 		return (*this);
	this->_value = src.getRawBits();
	return (*this);
}


/**********************************************************************************/
void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" <<  <<  "attacks" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" <<  <<  "took damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" <<  <<  "be repaired" << std::endl;
}




/**********************************************************************************/
