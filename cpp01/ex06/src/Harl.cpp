/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:55 by nimai             #+#    #+#             */
/*   Updated: 2023/08/04 16:58:53 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	
}

Harl::~Harl(void)
{	

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
	int	i;

	for (i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			break ;
	}
	switch (i)
	{
	case 0: std::cout << "[ DEBUG ]\n";
			this->debug();
			std::cout << std::endl;
	case 1: std::cout << "[ INFO ]\n";
			this->info();
			std::cout << std::endl;
	case 2: std::cout << "[ WARNING ]\n";
			this->warning();
			std::cout << std::endl;
	case 3: std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break ;
	default:std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
