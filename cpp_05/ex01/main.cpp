/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:55 by darismen          #+#    #+#             */
/*   Updated: 2025/01/22 13:16:21 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\033[1;32m Test Form \033[0m" << std::endl;
	Form fw("Wrong Form", 0, 0);
	std::cout << fw << std::endl;
	Form f1("Form 1", 1, 2);
	std::cout << f1 << std::endl;
	Form *f2 = new Form();
	std::cout << *f2 << std::endl;
	Form f3("Form 3", 40, 60);
	std::cout << f3 << std::endl;
	Form *f4 = new Form("HeapForm", 20, 20);
	std::cout << *f4 << std::endl;

	std::cout << "\033[1;32mEnd Form\033[0m" << std::endl;

	std::cout << "\033[1;32m Test Bureaucrat \033[0m" << std::endl;
	Bureaucrat b1("Bob", 1);
	Bureaucrat b2("Failure", 50);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	b1.signForm(f1);
	b2.signForm(f1);
	b2.signForm(*f2);
	b2.signForm(f3);
	
	delete f2;
	
	return 0;
}