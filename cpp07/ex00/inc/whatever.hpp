/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:26:50 by nimai             #+#    #+#             */
/*   Updated: 2024/02/28 16:03:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
	return ;
}

template <typename T>
T const & min(T const &a, T const &b)
{
	return a < b ? a : b;
}

template <typename T>
T const & max(T const &a, T const &b)
{
	return a > b ? a : b;
}

#endif // WHATEVER_HPP
