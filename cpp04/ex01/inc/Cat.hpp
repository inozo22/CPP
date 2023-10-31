/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:54 by nimai             #+#    #+#             */
/*   Updated: 2023/10/31 12:22:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal
{
public:
	Cat( void );
	Cat( std::string type );
	Cat( Cat const &src );
	~Cat( void );
	Cat &operator=( const Cat &src );

	Brain*		getBrain(void) const;
	// std::string		getType(void) const;

    void    makeSound( void ) const;

private:
	Brain * _brain;
};

#endif
