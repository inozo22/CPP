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

#include "Cure.hpp"

//***	constructor and destructor//constructor and destructor	***//
Cure::Cure( void ) : AMaterial("cure")
{
	std::cout << "Default constructor called in Cure." << std::endl;
}

// Cure::Cure( std::string name ) : type(DEFAULT_Cure)
// {
// 	std::cout << this->name << ": Created in Cure." << std::endl;
// }

Cure::~Cure(void)
{
//	delete (this->_brain);
//	std::cout << " in Cure destructor." << std::endl;
	std::cout << "Default destructor called in Cure." << std::endl;
}

Cure::Cure( const Cure &src ) : AMateria("cure")
{
	*this = src;
	std::cout << "Copy constructor called in Cure." << std::endl;
}

Cure &Cure::operator=( const Cure &src )
{
	if (this == &src)
		return *this;
	std::cout << "Cure assignment overload operator called." << std::endl;
	this->type = src.type;
	// this->type = src.getType();
/*	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*src._brain);*/
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
/*void	Cure::makeSound( void ) const
{
    std::cout << GREEN << this->type << ": " << Cure_SOUND << RESET << std::endl;
	return ;
}

Brain*	Cure::getBrain(void) const
{
	return (this->_brain);
}*/

AMateria *	Cure::clone( void ) const
{
	AMateria *	cureClone = new Cure();
	return (cureClone);
}

void	Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target << "’s wounds *" << std::endl;
}
/**********************************************************************************/
