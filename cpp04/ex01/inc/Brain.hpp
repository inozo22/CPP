/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:14 by nimai             #+#    #+#             */
/*   Updated: 2023/10/30 17:42:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>
# include "Animal.hpp"

class Brain
{
    public:
    
        Brain( void );
        ~Brain( void );
	    Brain( Brain const &src );
    	Brain &operator=( const Brain &src );


        static int const nb = 100;

    private:
        std::string _ideas[nb];

};

#endif
