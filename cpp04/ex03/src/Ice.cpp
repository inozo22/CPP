/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 10:25:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//***	constructor and destructor//constructor and destructor	***//
Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Default constructor called in Ice. type: " << this->type << std::endl;
}

Ice::~Ice(void)
{
//	delete (this->_brain);
//	std::cout << " in Ice destructor." << std::endl;
	std::cout << "Default destructor called in Ice." << std::endl;
}

Ice::Ice( const Ice &src ) : AMateria("ice")
{
//	this->_brain = NULL;
	*this = src;
	std::cout << "Copy constructor called in Ice." << std::endl;
}

Ice &Ice::operator=( const Ice &src )
{
	if (this == &src)
		return *this;
	std::cout << GREEN "Ice assignment overload operator called." RESET << std::endl;
	// this->type = src.getType();
	this->type = src.type;
/*	if (this->_brain != NULL)
		delete this->_brain;
	this->_brain = new Brain(*src._brain);*/
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
/*void	Ice::makeSound( void ) const
{
    std::cout << CYAN << this->type << ": " << Ice_SOUND << RESET << std::endl;
	return ;
}

Brain*	Ice::getBrain(void) const
{
	return (this->_brain);
}*/

AMateria *	Ice::clone( void ) const
{
	AMateria *	iceClone = new Ice();
	return (iceClone);
}


void	Ice::use(ICharacter& target)
{
	//std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
	(void)target;
}
/**********************************************************************************/
