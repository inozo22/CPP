/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:42:15 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 13:49:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
// #include <stdexcept>
// #include <algorithm>
// #include <iterator>

template <typename T>
typename T::const_iterator	EasyFind<T>::easyfind(T const & container, int element)
{
	typename T::const_iterator	iter;

	iter = std::find(container.begin(), container.end(), element);
	if (iter == container.end())
	{
		throw(std::out_of_range("Element is out of range."));
	}
	return (iter);
}
