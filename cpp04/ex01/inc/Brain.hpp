/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:14 by nimai             #+#    #+#             */
/*   Updated: 2023/12/22 18:15:43 by nimai            ###   ########.fr       */
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

		std::string	getIdeas(int i) const;
		void		setIdeas(int index, std::string const & idea);


	private:
		static int const _nb = 100;
		std::string _ideas[_nb];
		// std::string const _hundreadIdeas;

};

#endif
