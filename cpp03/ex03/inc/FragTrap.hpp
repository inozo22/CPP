/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:45:29 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 16:21:36 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# define FRAGTRAP_DEFAULT_HP 100
# define FRAGTRAP_DEFAULT_ENERGY 100
# define FRAGTRAP_DEFAULT_DAMAGE 30

// # include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
			FragTrap( void );
	public:
			FragTrap( std::string name );
			FragTrap( FragTrap const &src );
			~FragTrap( void );
			FragTrap &operator=( const FragTrap &src );

			void	highFiveGuys(void);
};
#endif
