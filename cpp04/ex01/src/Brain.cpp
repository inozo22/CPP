/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:41 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 18:17:08 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

//***	constructor and destructor//constructor and destructor	***//
Brain::Brain( void )
{
	// std::istringstream input;
	// input.str(this->_hundreadIdeas);
	// std::string line;
	// int	i = -1;
	// while (std::getline(input, line) && ++i < 100)
	// {
	// 	this->_ideas[i] = line;
	// }
	// for (std::string line; std::getline(input, line);)
	std::cout << "Default constructor called in Brain. _ideas[0]: " << this->_ideas[0] << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::string str = "idea no. ";
		std::ostringstream num;
		num << (i + 1);
		this->_ideas[i] = str + num.str();
	}
	// for (int i = 0; i < 100; i++)
	// 	std::cout << "idea: " << this->_ideas[i] << "\n";
	// std::cout << std::endl;
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
    for (int i = 0; i < this->_nb; i++)
    {
        this->_ideas[i] = src._ideas[i];
    }
	this->operator=(src);
}

Brain &Brain::operator=( const Brain &src )
{
	std::cout << "Brain assignment overload operator called." CLEAR << std::endl;
	for (int i = 0; i < this->_nb; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}
//***	constructor and destructor//constructor and destructor	***//

std::string		Brain::getIdeas(int index) const
{
	if (index < 0 || index > 99)
	{	
		std::cout << RED "index should not be negative number nor more than 99." CLEAR << std::endl;
		return (NULL);
	}
	// if (this->_ideas[index] == (std::string)NULL)
	// {
	// 	std::cout << RED "There is no idea." CLEAR << std::endl;
	// 	return (NULL);
	// }
	// std::cout << "Im here" << std::endl;
	return (this->_ideas[index]);
}

void	Brain::setIdeas(int index, std::string const & idea)
{
	if (index < 0 || index > 99)
	{	
		std::cout << RED "index should not be negative number nor more than 99." CLEAR << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
