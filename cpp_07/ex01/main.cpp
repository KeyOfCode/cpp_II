/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:54 by darismen          #+#    #+#             */
/*   Updated: 2025/08/04 19:40:52 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void float_func(float &f)
{
	f *= 3.3f;
}

void int_func(int &i)
{
	i *= 2;
}

void char_func(char &c)
{
	c = 'z';
}

void string_func(std::string &s)
{
	s = "changed";
}


int main( void ) {
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char b[] = {'a', 'b', 'c', 'd', 'e'};
	float c[2] = {1.1f, 2.2f};
	std::string d[] = {"one", "two", "three", "four", "five"};

	iter(a, 10, print_T);
	std::cout << std::endl;
	iter(b, 5, print_T);
	std::cout << std::endl;
	iter(c, 2, print_T);
	std::cout << std::endl;
	iter(d, 5, print_T);
	std::cout << std::endl;
	
	iter(a, 8, int_func);
	iter(b, 5, char_func);
	iter(c, 2, float_func);
	iter(d, 3, string_func);
	
	std::cout << std::endl << std::endl;

	iter(a, 10, print_T);
	std::cout << std::endl;
	iter(b, 5, print_T);
	std::cout << std::endl;
	iter(c, 2, print_T);
	std::cout << std::endl;
	iter(d, 5, print_T);
	std::cout << std::endl;
}
