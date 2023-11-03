/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 15:02:42 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//***	constructor and destructor//constructor and destructor	***//
Ice::Ice( void ) : AMateria("ice")
{
	// std::cout << "Default constructor called in Ice." << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Default destructor called in Ice." << std::endl;
}

Ice::Ice( const Ice &src ) : AMateria("ice")
{
	*this = src;
	// std::cout << "Copy constructor called in Ice." << std::endl;
}

Ice &Ice::operator=( const Ice &src )
{
	if (this == &src)
		return *this;
	// std::cout << GREEN "Ice assignment overload operator called." RESET << std::endl;
	this->type = src.type;
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
