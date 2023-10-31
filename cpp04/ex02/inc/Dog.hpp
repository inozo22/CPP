/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 16:06:52 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

class Dog : public AAnimal
{
public:
	Dog( void );
	Dog( std::string type );
	Dog( Dog const &src );
	~Dog( void );
	Dog &operator=( const Dog &src );

    Brain*		getBrain(void) const;

	// std::string		getType(void) const;

    void    makeSound( void ) const;

private:
	Brain * _brain;
};

#endif
