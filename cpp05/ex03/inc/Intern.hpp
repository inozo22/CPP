/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:47:43 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 13:05:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
			Intern( void );
			Intern( Intern const &src );
			~Intern( void );

			Intern & operator=(const Intern &src);

			AForm	makeForm( std::string const formName, std::string const target) const;

    
};




#endif