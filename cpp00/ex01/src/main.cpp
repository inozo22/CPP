/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:37:11 by nimai             #+#    #+#             */
/*   Updated: 2023/07/24 16:04:57 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/sample.hpp"

int	main()
{
	CSample obj;
	int num;

	std::cout << "input number:" << std::endl;
	std::cin >> num;

	obj.set(num);
	std::cout << obj.get() << std::endl;
	
	return 0;
}
