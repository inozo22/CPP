/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/11/01 12:16:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include <string>

class Cure : public AMaterial
{
	public:
			Cure( void );
//	Cure( std::string type );
			Cure( Cure const &src );
			~Cure( void );
			Cure &operator=( const Cure &src );

//	Brain*		getBrain(void) const;
//	std::string	const &getType(void) const;

			AMateria *	clone( void ) const;
//    void    makeSound( void ) const;
			void	use(ICharacter& target);
};

#endif
