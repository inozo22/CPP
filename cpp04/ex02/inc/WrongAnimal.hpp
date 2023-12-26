/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 16:12:44 by nimai            ###   ########.fr       */
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

# define DEFAULT_WRONGANIMAL "Human"
# define WRONGANIMAL_SOUND "*human groaning*"
# define WRONGCAT_SOUND "Bee bee..."

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

  				void    makeSound( void ) const;
				std::string		getType(void) const;
				std::string		getSound(void) const;
	
};
// std::ostream&	operator<<(std::ostream &out, Animal const &src);


#endif
