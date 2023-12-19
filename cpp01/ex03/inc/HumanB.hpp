/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 10:06:25 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
			HumanB( void );
			HumanB( std::string input_name );
			~HumanB( void );
			void	attack( void );
			void	setWeapon( Weapon &input_weapon );

	private:
			std::string name;
			Weapon *weapon;

};

#endif
