/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:59:37 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 16:25:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
    		std::string _name;

	public:
			DiamondTrap( void );
			DiamondTrap( std::string name );
			DiamondTrap( DiamondTrap const &src );
			~DiamondTrap( void );
			DiamondTrap &operator=( const DiamondTrap &src );

			using   ScavTrap::attack;
			void	whoAmI(void);
};

#endif
