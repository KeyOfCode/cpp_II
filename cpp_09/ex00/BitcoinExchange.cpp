/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:06:15 by darismen          #+#    #+#             */
/*   Updated: 2025/11/28 10:48:11 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::fstream &infile): _data(storeData(infile))  {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src): _data(src._data) {}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
		// this->_numbers = rhs._numbers;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

map BitcoinExchange::storeData(std::fstream &data)
{
	std::string line;
	std::string	date;
	std::string	rate;
	map			result;
	std::getline(data, line);
	while(std::getline(data, line))
	{
		date = line.substr(0, line.find(","));
		rate = line.substr(line.find(",") + 1);
		result[date] = atof(rate.c_str());
	}
	return result;
}

BitcoinExchange::c_iterator BitcoinExchange::findClosestRate(const std::string& date)
{
	c_iterator exact = this->_data.find(date);
	if (exact != this->_data.end())
		return exact;
	
	c_iterator lower = this->_data.upper_bound(date);
	if (lower == this->_data.begin()) {
		// Date is before all data entries
		throw InvalidDateException("Date too early");
	}
	--lower;
	return lower;
}

bool BitcoinExchange::validFormat(const std::string& line)
{
	if (line.length() < 13) return false;
	
	size_t separator_pos = line.find(" | ");
	if (separator_pos == std::string::npos || separator_pos != 10) {
		return false;
	}
	
	return true;
}

void BitcoinExchange::currentValue(std::fstream &input)
{
	std::string line;
	std::string	date;
	std::string	value;
	std::getline(input, line);
	while(std::getline(input, line))
	{
		try
		{
			if (!validFormat(line)) {
                throw InvalidInputException("Error: bad input => " + line);
            }
			date = line.substr(0, line.find(" | "));
			if (validDate(date) == false)
				throw InvalidDateException(date);
			
			value = line.substr(line.find(" | ") + 3);
			if (value.empty())
				throw InvalidInputException("Error: Missing value");
			float f_value = atof(value.c_str());
			validInput(f_value);

			
			c_iterator correct_date = findClosestRate(date);
			std::cout 	<< date << " => " << value << " = " 
						<< correct_date->second * f_value << std::endl;
			
		} catch (const InvalidDateException &e) {
			std::cout << e.what() << std::endl;
			continue;
		} catch (const InvalidInputException &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}

bool BitcoinExchange::validDate(std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month  = date.substr(5, 2);
	std::string day  = date.substr(8, 2);

	int v_year = atoi(year.c_str());
	int v_month = atoi(month.c_str());
	int v_day = atoi(day.c_str());
	
	if (v_year < 2009 || v_year > 2021	)
		return false;
		
	if (v_month < 1 || v_month > 12)
		return false;

	if (v_day < 1 || v_day > 31)
		return false;
	
	return true;
}

bool BitcoinExchange::validInput(float input)
{		
	if (input < 0)
		throw InvalidInputException("Error: not a positive number.");
	if (input > 1000)
		throw InvalidInputException("Error: too large a number.");
	return true;
}


