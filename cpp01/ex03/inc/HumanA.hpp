/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/19 10:06:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
			HumanA( std::string input_name, Weapon &input_weapon );
			~HumanA( void );
			void	attack( void );

	private:
			std::string name;
			Weapon &weapon;

};


#endif
