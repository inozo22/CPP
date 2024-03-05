/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:02:27 by nimai             #+#    #+#             */
/*   Updated: 2023/12/13 15:35:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>

//# define MAX_N 750

class Span
{
	private:
   		unsigned int		_max;
		std::vector<int>	_numbers;
	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const &src );
		~Span();

		Span & operator=( const Span & src );

		void	addNumber( unsigned int Element );
		int		shortestSpan( void );
		int		longestSpan( void );
};





#endif
