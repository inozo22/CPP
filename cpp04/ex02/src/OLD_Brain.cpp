/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:41 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 16:03:32 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//***	constructor and destructor//constructor and destructor	***//
Brain::Brain( void )
{
	std::cout << "Default constructor called in Brain. _ideas[0]: " << this->_ideas[0] << std::endl;
}

// Brain::Brain( std::string type ) : type(type)
// {
// 	std::cout << this->type << ": Created in Brain." << std::endl;
// }

Brain::~Brain(void)
{	
	std::cout << "Default destructor called in Brain";
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
	std::cout << GREEN "Brain assignment overload operator called." RESET << std::endl;
	for (int i = 0; i < this->nb; i++)
		this->_ideas[i] = src._ideas[i];
	// if (this != &src)
	// {
	// 	// this->type = src.getType();
	// }
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//

std::string		Brain::getIdeas(int index) const
{
	if (index < 0 || index > 99)
	{	
		std::cout << RED "index should not be negative number nor more than 99." RESET << std::endl;
		return (NULL);
	}
	// if (this->_ideas[index] == (std::string)NULL)
	// {
	// 	std::cout << RED "There is no idea." RESET << std::endl;
	// 	return (NULL);
	// }
	// std::cout << "Im here" << std::endl;
	return (this->_ideas[index]);
}

void	Brain::setIdeas(int index, std::string const & idea)
{
	if (index < 0 || index > 99)
	{	
		std::cout << RED "index should not be negative number nor more than 99." RESET << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
