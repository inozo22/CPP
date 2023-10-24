/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/10/24 16:53:27 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"
# define UTEST "TEST"
# define LTEST "test"

# include <iostream>

class ClapTrap 
{

private:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_energy;
	unsigned int	_damage;

public:
	static unsigned int const	defaultHp = 10;
	static unsigned int const	defaultEnergy = 10;
	static unsigned int const	defaultDamage = 0;

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const &src );
	~ClapTrap( void );
	ClapTrap &operator=( const ClapTrap &src );

	std::string		getName(void) const;
	unsigned int	getHp(void) const;
	unsigned int	getEnergy(void) const;
	unsigned int	getDamage(void) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
};

#endif
