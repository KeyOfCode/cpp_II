/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:53:41 by darismen          #+#    #+#             */
/*   Updated: 2025/11/20 11:25:19 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>
T const & min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}
template <typename T>
T const & max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}
#endif