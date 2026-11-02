/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:10:26 by darismen          #+#    #+#             */
/*   Updated: 2025/11/28 14:23:10 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw RPN::InvalidInputException("Invalid input");
		RPN line;
		line.operations(argv[1]);
	}
	catch (RPN::InvalidInputException &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	
}