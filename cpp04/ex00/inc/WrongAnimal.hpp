/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/10/27 12:02:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define CLEAR "\033[0m"
# define UTEST "TEST"
# define LTEST "test"

# define DEFAULT_WRONGANIMAL "Human"
# define DOG_SOUND "Woof woof!"
# define CAT_SOUND "Meaw"

# include <iostream>
# include <string>

class WrongAnimal 
{

protected:
	std::string		type;

public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( WrongAnimal const &src );
	~WrongAnimal( void );
	WrongAnimal &operator=( const WrongAnimal &src );

	std::string		getType(void) const;
	// unsigned int	getHp(void) const;
	// unsigned int	getEnergy(void) const;
	// unsigned int	getDamage(void) const;

	// void	attack(const std::string& target);
	// void	takeDamage(unsigned int amount);
	// void	beRepaired(unsigned int amount);
    void    makeSound( void ) const;
	
};

#endif
