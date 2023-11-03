/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:50:58 by nimai             #+#    #+#             */
/*   Updated: 2023/11/03 16:04:08 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <string>

class Bureaucrat
{
	private:
			std::string const _name;
			int	_grade;
	public:
			Bureaucrat( void );
			Bureaucrat( Bureaucrat const & src);
			Bureaucrat( std::string const & name, int grade );
			~Bureaucrat( void );

			Bureaucrat & operator=(const Bureaucrat &src);

			std::string const &	getName( void ) const;
			int	getGrade( void );  
};
#endif
