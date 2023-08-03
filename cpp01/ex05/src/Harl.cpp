/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/03 14:04:26 by nimai            ###   ########.fr       */
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
	std::cout << "You got the debug" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "You got the info" << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "You got the warning" << std::endl;
}
void	Harl::error( void )
{
	std::cout << "You got the error" << std::endl;
}
void	Harl::complain( std::string level )
{
	std::cout << "You got the complain" << std::endl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	//ここまで
}
