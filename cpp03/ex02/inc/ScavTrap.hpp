/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/10/25 16:57:40 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# define SCAVTRAP_DEFAULT_HP 100
# define SCAVTRAP_DEFAULT_ENERGY 50
# define SCAVTRAP_DEFAULT_DAMAGE 20

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

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
