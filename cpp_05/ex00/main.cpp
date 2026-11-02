/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:55 by darismen          #+#    #+#             */
/*   Updated: 2025/01/17 13:57:16 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void executeNull()
{
	std::cout << std::endl;
	std::cout << "\033[1;34m------- test wrong Bureaucrat -------\033[0m" << std::endl;
	Bureaucrat b0("Wong", 0);
	Bureaucrat b1("Bong", 173);
	std::cout << b0 << std::endl;
	std::cout << b1 << std::endl;
}

void executeNormal()
{
	std::cout << std::endl;
	std::cout << "\033[1;34m------- test Bureaucrat -------\033[0m" << std::endl;
	Bureaucrat b0("rubén", 23);
	b0.gradeDown();
	b0.gradeDown();
	b0.gradeDown();
	std::cout << b0 << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;34m------- test copy -------\033[0m" << std::endl;
	Bureaucrat b1("Pepe", 1);
	std::cout << b1 << std::endl;
	b1.gradeDown();
	Bureaucrat b2(b1);
	std::cout << b2 << std::endl;
	
	std::cout << std::endl;
	std::cout << "\033[1;34m------- test asignation -------\033[0m" << std::endl;
	Bureaucrat b3("jose", 5);
	std::cout << b3 << std::endl;
		b3 = b2;
	std::cout << b3 << std::endl;
}

void executeHigh()
{
	std::cout << std::endl;
	std::cout << "\033[1;34m------- Bureaucrat High -------\033[0m" << std::endl;
	Bureaucrat b3("Pepe", 1);
	std::cout << b3 << std::endl;
	b3.gradeUp();
	std::cout << b3 << std::endl;
}

void executeLow()
{
	std::cout << std::endl;
	std::cout << "\033[1;34m------- Bureaucrat Low -------\033[0m" << std::endl;
	Bureaucrat b4("Antonio", 150);
	std::cout << b4 << std::endl;
	b4.gradeDown();
	std::cout << b4 << std::endl;
}

int main()
{
	executeNull();
	executeNormal();
	executeLow();
	executeHigh();

	return 0;
}