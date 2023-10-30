/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:41 by nimai             #+#    #+#             */
/*   Updated: 2023/10/30 17:43:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//***	constructor and destructor//constructor and destructor	***//
Brain::Brain( void )
{
	std::cout << "Default constructor called in Brain. type: " << std::endl;
}

// Brain::Brain( std::string type ) : type(type)
// {
// 	std::cout << this->type << ": Created in Brain." << std::endl;
// }

Brain::~Brain(void)
{	
	std::cout << "Default destructor called in Brain." << std::endl;
}

Brain::Brain( const Brain &src )
{
	std::cout << "Copy constructor called in Brain." << std::endl;
    for (int i = 0; i < this->nb; i++)
    {
        this->_ideas[i] = src._ideas[i];
    }
	this->operator=(src);
}

Brain &Brain::operator=( const Brain &src )
{
	std::cout << GREEN "Brain assignment overload operator called." CLEAR << std::endl;
	if (this != &src)
	{
		// this->type = src.getType();
	}
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//

