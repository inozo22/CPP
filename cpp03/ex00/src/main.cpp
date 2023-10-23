/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:06:00 by nimai             #+#    #+#             */
/*   Updated: 2023/10/23 16:41:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	taro("taro");
	ClapTrap	ichiro = ClapTrap();
	ClapTrap	copyClap = ClapTrap(taro);

	taro.attack("_undefined");
	ichiro.takeDamage(0);
	ichiro.beRepaired(10);
	return (0);
	return 0;
}


