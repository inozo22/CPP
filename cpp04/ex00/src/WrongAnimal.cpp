/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:03:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//***	constructor and destructor//constructor and destructor	***//
WrongAnimal::WrongAnimal( void ) : type(DEFAULT_WRONGANIMAL)
{
	std::cout << "Default constructor called in WrongAnimal. type: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
	std::cout << this->type << ": Created in WrongAnimal." << std::endl;
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
    std::cout << RED << this->type << ": *human groaning*" CLEAR << std::endl;
	return ;
}

std::string		WrongAnimal::getType(void) const
{
	return (this->type);
}

/**********************************************************************************/
