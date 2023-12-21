/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/12/21 14:28:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define CLEAR   "\x1b[0m"

# define CLAPTRAP_DEFAULT_HP 10
# define CLAPTRAP_DEFAULT_ENERGY 10
# define CLAPTRAP_DEFAULT_DAMAGE 0

# include <string>

class ClapTrap 
{
	protected:
			std::string		name;
			unsigned int	hp;
			unsigned int	energy;
			unsigned int	damage;
			unsigned int	max_hp;

	public:
			ClapTrap( void );
			ClapTrap( std::string name );
			ClapTrap( ClapTrap const &src );
			~ClapTrap( void );
			ClapTrap &operator=( const ClapTrap &src );

			std::string		getName(void) const;
			unsigned int	getHp(void) const;
			unsigned int	getEnergy(void) const;
			unsigned int	getDamage(void) const;
			unsigned int	getMaxHp(void) const;

			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
};

#endif
