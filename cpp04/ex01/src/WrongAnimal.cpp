/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:05:27 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 16:12:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

//***	constructor and destructor//constructor and destructor	***//
WrongAnimal::WrongAnimal( void ) : type(DEFAULT_WRONGANIMAL)
{
	std::cout << "Default constructor called in WrongAnimal. type: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
	std::cout << "TYPE: " << this->type << ": Created in WrongAnimal." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{	
	std::cout << this->type << ": Default destructor called in WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	std::cout << this->type << ": Copy constructor called in WrongAnimal." << std::endl;
	this->operator=(src);
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &src )
{
	std::cout << GREEN "WrongAnimal assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/
void	WrongAnimal::makeSound( void ) const
{
    std::cout << YELLOW << this->type << ": " << this->getSound() << CLEAR << std::endl;
	return ;
}

std::string		WrongAnimal::getType(void) const
{
	return (this->type);
}

std::string		WrongAnimal::getSound(void) const
{
	return (WRONGANIMAL_SOUND);
}

/**********************************************************************************/

// std::ostream&	operator<<(std::ostream &out, WrongAnimal const &src)
// {
// 	out << "What does the " << src.getType() << " say " << src.getSound();
// 	return (out);
// }
