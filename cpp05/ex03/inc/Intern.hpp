/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:47:43 by nimai             #+#    #+#             */
/*   Updated: 2023/11/23 16:38:25 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
			Intern( void );
			Intern( Intern const &src );
			~Intern( void );

			Intern & operator=(const Intern &src);

			AForm	*makeForm( std::string formName, std::string target);

			class InvalidFormName : public std::exception
			{
				public:
						virtual const char *	what(void) const throw();
			};


    
};

#endif
