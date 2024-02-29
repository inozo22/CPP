/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:44:54 by nimai             #+#    #+#             */
/*   Updated: 2024/02/29 08:58:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"

# include <iostream>
# include <cstdlib>

// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.

// for template function
template<typename T>
void	iter(T* array, size_t len, void function(T const&))
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
}

// for not template function
template <typename T, typename F>
void	iter(T* array, size_t len, F function)
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
}

template <typename T>
void	printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void	sumFive(T& element)
{
	element += 5;
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


// Turn in a main.cpp file that contains your tests. Provide enough code to generate a test executable.
// Your iter function template must work with any type of array. The third parameter can be an instantiated function template.
