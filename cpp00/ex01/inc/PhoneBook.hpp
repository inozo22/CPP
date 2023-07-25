/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:04:40 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 16:21:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define PHONEBOOK "phonebook ☏ "
# define USAGE "USAGE: ADD / SEARCH / EXIT"
# define MAX_CONTACT 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	cmd_add();
		void	cmd_search();
		void	cmd_exit();
	private:
		Contact	contact[MAX_CONTACT];
		int		_pos;
		int		_line;
		int		_id;
	
	
	
};

#endif
