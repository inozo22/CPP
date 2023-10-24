/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:04:40 by nimai             #+#    #+#             */
/*   Updated: 2023/10/24 12:29:56 by nimai            ###   ########.fr       */
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
# define USAGE_SEARCH "please input one of index, or, 'q' or 'Q' to quit search command."
# define MAX_CONTACT 8
# define COLOR_RESET	"\001\033[0m\002"
# define COLOR_GREEN	"\001\033[1;32m\002"
# define COLOR_YELLOW	"\001\033[1;33m\002"
# define COLOR_GRAY		"\001\033[2;37m\002"
# define COLOR_CURSIVE	"\001\033[3m\002"
# define COLOR_RED		"\001\033[31m\002"
# define COLOR_BLUE		"\001\033[1;34m\002"
# define COLOR_CYAN 	"\001\033[1;36m\002"
# define COLOR_ACCENT	"\001\033[92;3;4;1m\002"

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
