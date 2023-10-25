/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:45:29 by nimai             #+#    #+#             */
/*   Updated: 2023/10/25 16:57:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# define FRAGTRAP_DEFAULT_HP 100
# define FRAGTRAP_DEFAULT_ENERGY 100
# define FRAGTRAP_DEFAULT_DAMAGE 30

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap const &src );
	~FragTrap( void );
	FragTrap &operator=( const FragTrap &src );

	void	highFiveGuys(void);
};

#endif