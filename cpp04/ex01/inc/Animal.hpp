/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 17:05:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define CLEAR "\033[0m"

# define DEFAULT_ANIMAL "Bird[MY FAVORITE DEFAULT ANIMAL]"
# define DOG_SOUND "Woof woof!"
# define CAT_SOUND "Meaw"
# define BIRD_SOUND "Piyo piyo"

# include <iostream>
# include <string>

class Animal 
{

	protected:
				std::string		type;

	public:
				Animal( void );
				Animal( std::string type );
				Animal( Animal const &src );
				virtual ~Animal( void );
				Animal &operator=( const Animal &src );

  				virtual void    makeSound( void ) const;
				std::string		getType(void) const;
				virtual std::string		getSound(void) const;
	
};
// std::ostream&	operator<<(std::ostream &out, Animal const &src);


#endif
