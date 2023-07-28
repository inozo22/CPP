/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:19 by nimai             #+#    #+#             */
/*   Updated: 2023/07/28 15:26:36 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"

# include <string>
# include <iostream>
# include <iomanip>

class Zombie {


public:

	Zombie( std::string name );
	~Zombie( void );
	void	announce( void );

private:
    std::string name;

};

Zombie*	zombieHorde( int N, std::string name );

#endif
