/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/26 11:18:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

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

class AAnimal 
{
	private:

	protected:
				AAnimal( void );
				AAnimal( std::string type );
				std::string		type;

	public:
				AAnimal( AAnimal const &src );
				virtual ~AAnimal( void );
				AAnimal &operator=( const AAnimal &src );

  				virtual void    makeSound( void ) const = 0;
				std::string		getType(void) const;
				virtual std::string		getSound(void) const = 0;
	
};
// std::ostream&	operator<<(std::ostream &out, Animal const &src);


#endif
