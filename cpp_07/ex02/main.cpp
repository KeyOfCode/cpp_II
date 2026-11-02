/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:54 by darismen          #+#    #+#             */
/*   Updated: 2025/08/04 20:13:05 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
int main( void )
{
	try
	{
		Array<int> intArray(5);

		std::cout << "Size of intArray: " << intArray.size() << std::endl;

		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

		std::cout << "intArray: " << intArray << std::endl;
			
		Array<std::string> strArray(3);
		strArray[0] = "apple";
		strArray[1] = "banana";
		strArray[2] = "cherry";

		std::cout << "\nSize of strArray: " << strArray.size() << std::endl;
		
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

		std::cout << "strArray: " << strArray << std::endl;

		// Triggering exception
		std::cout << "\nTriggering out-of-bound exception..." << std::endl;
		std::cout << strArray[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}


 /* 
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time(NULL)
#include <iostream>
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

 */