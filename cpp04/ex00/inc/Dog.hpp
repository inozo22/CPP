/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 15:13:52 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal
{
	public:
			Dog( void );
			Dog( std::string type );
			Dog( Dog const &src );
			~Dog( void );
			Dog &operator=( const Dog &src );

			// std::string		getType(void) const;

			void    makeSound( void ) const;
			std::string	getSound( void ) const;
};
// std::ostream&	operator<<(std::ostream &out, Dog const &src);

#endif
