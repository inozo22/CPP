/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:00:17 by nimai             #+#    #+#             */
/*   Updated: 2023/12/11 17:11:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class	Array
{
	public:
			T Array( void );
			T Array( unsigned int );
			T Array( Array const & src );
			T ~Array( void );



	private:




};

template <typename A, typename F>
void	iter(A * array, size_t len, F function)
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
	return ;
}

template <typename T>
void	print(T * array, size_t len)
{
	std::cout << "Array: {";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << array[i];
		if ((i + 1 != len))
			std::cout << ", ";
	}
	std::cout << "}";
}




#endif
