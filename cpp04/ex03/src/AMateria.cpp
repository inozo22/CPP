/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:49 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:03:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//***	constructor and destructor//constructor and destructor	***//
AMateria::AMateria( void ) : type("Dfault")
{
	std::cout << "Default constructor called in AMateria. type: " << this->type << std::endl;
}

AMateria::AMateria( std::string const & type ) : type(type)
{
	std::cout << this->type << ": Created in AMateria." << std::endl;
}

AMateria::~AMateria(void)
{	
	std::cout << this->type << ": Default destructor called in AMateria." << std::endl;
}

// AMateria::AMateria( const AMateria &src )
// {
// 	std::cout << this->type << ": Copy constructor called in AMateria." << std::endl;
// 	this->operator=(src);
// }

AMateria &AMateria::operator=( const AMateria &src )
{
	std::cout << GREEN "AMateria assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//


/**********************************************************************************/

std::string	const	&AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
    std::cout << "I don't know what should I use" << std::endl;
}

/**********************************************************************************/
