/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 15:07:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
Animal::Animal( void ) : type(DEFAULT_ANIMAL)
{
	std::cout << "Default constructor called in Animal. type: " << this->type << std::endl;
}

Animal::Animal( std::string type ) : type(type)
{
	std::cout << "TYPE: " << this->type << ": Created in Animal." << std::endl;
}

Animal::~Animal(void)
{	
	std::cout << this->type << ": Default destructor called in Animal." << std::endl;
}

Animal::Animal( const Animal &src )
{
	std::cout << this->type << ": Copy constructor called in Animal." << std::endl;
	this->operator=(src);
}

Animal &Animal::operator=( const Animal &src )
{
	std::cout << GREEN "Animal assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	Animal::makeSound( void ) const
{
    std::cout << YELLOW << this->type << ": " << this->getSound() << CLEAR << std::endl;
	return ;
}

std::string		Animal::getType(void) const
{
	return (this->type);
}

std::string		Animal::getSound(void) const
{
	return (BIRD_SOUND);
}

/**********************************************************************************/

// std::ostream&	operator<<(std::ostream &out, Animal const &src)
// {
// 	out << "What does the " << src.getType() << " say " << src.getSound();
// 	return (out);
// }
