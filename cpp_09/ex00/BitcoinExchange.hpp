/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:00:04 by darismen          #+#    #+#             */
/*   Updated: 2026/09/29 14:55:54 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include <ctime>


typedef std::map<std::string, float> map;

class BitcoinExchange
{
private:
	map 	_data;
	
public:
	typedef map::const_iterator c_iterator;
	BitcoinExchange();
	BitcoinExchange(std::fstream &infile);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator = (const BitcoinExchange &rhs);
	~BitcoinExchange();
	
	map storeData(std::fstream &data);
	void currentValue(std::fstream &input);
	bool validFormat(const std::string& line);
	bool validDate(std::string date);
	bool validInput(float input);
	c_iterator findClosestRate(const std::string& date);

	class InvalidInputException : public std::exception
		{
			private:
				std::string			_error;
			public:
				InvalidInputException(const std::string &msg): _error(msg)
					{_error = "\033[0;31m" + msg + "\033[0m";}
				virtual	~InvalidInputException() throw() {}
				virtual const char	*what(void)	const throw() {return (this->_error.c_str());}
		};
	class InvalidDateException : public std::exception
	{
		private:
			std::string _error;
		public:
			InvalidDateException(const std::string &date) 
				{_error = "\033[0;31mError: bad date => " + date + "\033[0m";}
			virtual	~InvalidDateException() throw() {}
			virtual const char *what() const throw() {return _error.c_str();}
	};
};

std::ostream &operator << (std::ostream &o, BitcoinExchange const &a);


#endif