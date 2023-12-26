/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 16:11:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include <iostream>
#include <string>

//***	constructor and destructor//constructor and destructor	***//
Cure::Cure( void ) : AMateria("cure")
{
	// std::cout << "Default constructor called in Cure." << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Destructor called in Cure." << std::endl;
}

Cure::Cure( const Cure &src ) : AMateria("cure")
{
	*this = src;
	// std::cout << "Copy constructor called in Cure." << std::endl;
}

Cure &Cure::operator=( const Cure &src )
{
	if (this == &src)
		return *this;
	// std::cout << "Cure assignment overload operator called." << std::endl;
	this->type = src.type;
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/

AMateria *	Cure::clone( void ) const
{
	AMateria *	cureClone = new Cure();
	return (cureClone);
}

void	Cure::use(ICharacter& target)
{
    //std::cout << "* heals " << target << "'s wounds *" << std::endl;
	(void)target;
}
/**********************************************************************************/
