/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:42:15 by nimai             #+#    #+#             */
/*   Updated: 2024/03/09 10:25:29 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include "easyfind.hpp"
# include <stdexcept>
# include <algorithm>
// # include <iterator>
# include <iostream>

template <typename T>
typename T::const_iterator	easyfind(T const & container, int element)
{
	typename T::const_iterator	iter;

	iter = std::find(container.begin(), container.end(), element);
	if (iter == container.end())
	{
		std::cout << "Element " MAGENTA << element << RESET " ";
		throw std::out_of_range("is not found.");
	}
	return (iter);
}
// template <typename T>
// typename T::const_iterator	easyfind(T const & container, int element)
// {
// 	typename T::const_iterator	iter;

// 	iter = std::find(container.begin(), container.end(), element);
// 	if (iter == container.end())
// 	{
// 		throw(std::out_of_range("Element is out of range."));
// 	}
// 	return (iter);
// }
#endif
