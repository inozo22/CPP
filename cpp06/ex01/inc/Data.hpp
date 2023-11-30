/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:20:11 by nimai             #+#    #+#             */
/*   Updated: 2023/11/30 15:44:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include "colors.h"

struct Data
{
    unsigned int    value;
    std::string     str;	
};
uintptr_t   serialize( Data * ptr );
Data *      deserialize( uintptr_t raw );
std::ostream &  operator<<( std::ostream &os, const Data & obj );

#endif
