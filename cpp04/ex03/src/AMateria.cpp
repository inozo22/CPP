/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMaterial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:03:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//***	constructor and destructor//constructor and destructor	***//
AMaterial::AMaterial( void ) : type("Dfault")
{
	std::cout << "Default constructor called in AMaterial. type: " << this->type << std::endl;
}

AMaterial::AMaterial( std::string type ) : type(type)
{
	std::cout << this->type << ": Created in AMaterial." << std::endl;
}

AMaterial::~AMaterial(void)
{	
	std::cout << this->type << ": Default destructor called in AMaterial." << std::endl;
}

// AMaterial::AMaterial( const AMaterial &src )
// {
// 	std::cout << this->type << ": Copy constructor called in AMaterial." << std::endl;
// 	this->operator=(src);
// }

AMaterial &AMaterial::operator=( const AMaterial &src )
{
	std::cout << GREEN "AMaterial assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/

std::string		AMaterial::getType(void) const
{
	return (this->type);
}

void AMaterial::use(ICharacter& target)
{
    std::cout << "I don't know what should I use" << std::endl;
}

/**********************************************************************************/
