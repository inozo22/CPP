/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 13:03:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"

# define SCAVTRAP_DEFAULT_HP 100
# define SCAVTRAP_DEFAULT_ENERGY 50
# define SCAVTRAP_DEFAULT_DAMAGE 20

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

// private:
// 	std::string		_name;
// 	unsigned int	_hp;
// 	unsigned int	_energy;
// 	unsigned int	_damage;

	public:
			ScavTrap( void );
			ScavTrap( std::string name );
			ScavTrap( ScavTrap const &src );
			~ScavTrap( void );
			ScavTrap &operator=( const ScavTrap &src );

			void	attack(const std::string& target);
			void	guardGate(void);
};

#endif
