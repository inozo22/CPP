/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/04 11:10:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	
}

Harl::~Harl(void)
{	
	//std::cout << this->_filename << " has left from the field." << std::endl;
}

void	Harl::debug( void )
{
	std::cout << MSG_DEBUG << std::endl;
}
void	Harl::info( void )
{
	std::cout << MSG_INFO << std::endl;
}
void	Harl::warning( void )
{
	std::cout << MSG_WARNING << std::endl;
}
void	Harl::error( void )
{
	std::cout << MSG_ERROR << std::endl;
}
void	Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Pointer pointer[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	for (i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*pointer[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "doesn't match" << std::endl;
}
