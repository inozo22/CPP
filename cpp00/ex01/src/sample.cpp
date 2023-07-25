/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:54 by nimai             #+#    #+#             */
/*   Updated: 2023/07/25 10:47:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/sample.hpp"

// void	CSample::set(int num)
// {
// 	m_num = num;
// }

// int	CSample::get()
// {
// 	return m_num;
// }
void	Sample::func1()
{
	std::cout << "func1" << std::endl;
	a = 1;
	b = 1;
	std::cout << "func1: a = " << a << ", b = " << b << std::endl;
	func2();
}
void	Sample::func2()
{
	a = 2;
	b = 2;
	std::cout << "func2: a = " << a << ", b = " << b << std::endl;
}
