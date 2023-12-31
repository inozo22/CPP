/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 11:24:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
AAnimal::AAnimal( void ) : type(DEFAULT_ANIMAL)
{
	std::cout << "Default constructor called in Animal. type: " << this->type << std::endl;
}

AAnimal::AAnimal( std::string type ) : type(type)
{
	std::cout << "TYPE: " << this->type << ": Created in Animal." << std::endl;
}

AAnimal::~AAnimal(void)
{	
	std::cout << this->type << ": Destructor called in Animal." << std::endl;
}

AAnimal::AAnimal( const AAnimal &src )
{
	std::cout << this->type << ": Copy constructor called in Animal." << std::endl;
	this->operator=(src);
}

AAnimal &AAnimal::operator=( const AAnimal &src )
{
	std::cout << GREEN "AAnimal assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
// void	AAnimal::makeSound( void ) const
// {
//     std::cout << YELLOW << this->type << ": " << this->getSound() << CLEAR << std::endl;
// 	return ;
// }

std::string		AAnimal::getType(void) const
{
	return (this->type);
}

// std::string		AAnimal::getSound(void) const
// {
// 	return (BIRD_SOUND);
// }

/**********************************************************************************/

// std::ostream&	operator<<(std::ostream &out, Animal const &src)
// {
// 	out << "What does the " << src.getType() << " say " << src.getSound();
// 	return (out);
// }
