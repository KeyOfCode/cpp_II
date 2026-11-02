/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:07:08 by darismen          #+#    #+#             */
/*   Updated: 2025/11/20 11:28:15 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, int lenght, F f)
{
	for (int i = 0; i < lenght; i++)
		f(array[i]);
}

template <typename T>
void print_T(T & a)
{
	std::cout << a << " ";
}

#endif