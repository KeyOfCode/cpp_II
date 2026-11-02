/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:56:16 by darismen          #+#    #+#             */
/*   Updated: 2025/03/18 11:29:09 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

void ScalarConverter::convert(const std::string str)
{
	if (infinities(str))
		return;
	try
	{
		int intVal;
		std::stringstream(str) >> intVal;
		char c = static_cast<char>(intVal);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
	}

	try
	{
		int intVal;
		std::stringstream(str) >> intVal;
		std::cout << "int: " << intVal << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		float floatVal;
		if (str[str.size() - 1] == 'f')
		{
			std::string floatStr = str.substr(0, str.size() - 1);
			std::istringstream(floatStr) >> floatVal;
		}
		else
		{
			std::istringstream(str) >> floatVal;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << floatVal << "f" << std::endl;
	
	}
	catch (const std::exception &e)
	{
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		double doubleVal;
		if (str[str.size() - 1] == 'f')
		{
			std::string floatStr = str.substr(0, str.size() - 1);
			std::istringstream(floatStr) >> doubleVal;
		}
		else
		{
			std::istringstream(str) >> doubleVal;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << doubleVal << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::infinities(const std::string str)
{
	if (str == "inf" || str == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return true;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	else if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	return false;
}

/* void ScalarConverter::convert(const std::string input)
{
	// double value;
	if (input == "inf" || input == "inff")
	{
		processValues(std::numeric_limits<double>::infinity());
		return;
	}
	else if (input == "-inf" || input == "-inff")
	{
		processValues(-std::numeric_limits<double>::infinity());
		return;
	}
	else if (input == "nan" || input == "nanf")
	{
		processValues(std::numeric_limits<double>::quiet_NaN());
		return;
	}

	if (input[input.size() - 1] == 'f')
	{
		std::string floatStr = input.substr(0, input.size() - 1);
		std::istringstream ssFloat(floatStr);
		float floatVal;
		if (ssFloat >> floatVal && ssFloat.eof())
		{
			processValues(static_cast<double>(floatVal));
			return;
		}
	}
	std::stringstream ssInt(input);
	int intVal;
	if (ssInt >> intVal && ssInt.eof())
	{
		processValues(static_cast<double>(intVal));
		return;
	}

	// Try to convert to double
	std::stringstream ssDouble(input);
	double doubleVal;
	if (ssDouble >> doubleVal && ssDouble.eof())
	{
		processValues(doubleVal);
		return;
	}

	// If none of the above, then it's invalid input
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
} */

/* void ScalarConverter::processValues(double value)
{
	try 
	{
		if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		{
			std::cout << "char: ";
			throw std::exception();
		}
		if (std::isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	try
	{
		if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		{
			std::cout << "int: ";
			throw std::exception();
		}
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "impossible" << '\n';
	}
	
	if (std::isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else
	{	
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(value) << "f" << std::endl;
	}
		
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< value << std::endl;
} */
