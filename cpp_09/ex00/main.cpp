/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:59:10 by darismen          #+#    #+#             */
/*   Updated: 2026/09/29 15:21:14 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	try 
	{
		if (argc != 2)
			throw BitcoinExchange::InvalidInputException("No input detected");

		std::fstream data("data.csv");
		if (!data.is_open())
			throw BitcoinExchange::InvalidInputException("Error: Could not open data.csv");
		
		std::fstream input(argv[1]);
		if (!input.is_open())
			throw BitcoinExchange::InvalidInputException("Error: Could not open input file");

		BitcoinExchange rate(data);
		rate.currentValue(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}