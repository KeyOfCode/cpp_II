/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:40:58 by darismen          #+#    #+#             */
/*   Updated: 2025/11/20 11:37:58 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::list<int> lst(arr, arr + 5);
	lst.push_back(42);
	lst.push_back(21);

	try 
	{
		std::list<int>::iterator it = easyfind(lst, 21);
		std::cout << "Found in lst: " << *it << std::endl;
	}
	catch (const std::exception &e) {std::cerr << e.what() << std::endl;}
	
	std::vector<int> vec(arr, arr + 5);
	try 
	{
		std::vector<int>::iterator it = easyfind(vec, 21);
		std::cout << "Found in vec: " << *it << std::endl;
	}
	catch (const std::exception &e) {std::cerr << e.what() << std::endl;}
	return (0);
}