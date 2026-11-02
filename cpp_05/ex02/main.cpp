/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:55 by darismen          #+#    #+#             */
/*   Updated: 2025/03/08 18:37:54 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b1("Bob", 1);
	Bureaucrat b2("Failure", 149);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	
	std::cout << std::endl << "\033[1;32m Test PresidentialPardon \033[0m" << std::endl;
	PresidentialPardonForm ppf("Evil");
	PresidentialPardonForm ppf2("Saint");
	std::cout << ppf << std::endl;
	std::cout << ppf2 << std::endl;
	b1.signForm(ppf);
	b1.executeForm(ppf);
	b2.signForm(ppf2);
	b2.executeForm(ppf2);

	std::cout << std::endl << "\033[1;32m Test RobotomyRequest \033[0m" << std::endl;

	RobotomyRequestForm rrf("Robocop");
	RobotomyRequestForm rrf2("Terminator");
	std::cout << rrf << std::endl;
	std::cout << rrf2 << std::endl;
	b1.signForm(rrf);
	b1.executeForm(rrf);
	b1.executeForm(rrf2);

	std::cout << std::endl << "\033[1;32m Test RobotomyRequest \033[0m" << std::endl;

	ShrubberyCreationForm scf("Home");
	ShrubberyCreationForm scf2("White House");
	std::cout << scf << std::endl;
	std::cout << scf2 << std::endl;
	b1.signForm(scf);
	b1.executeForm(scf);
	b1.executeForm(scf2);


	std::cout << "\033[1;32mEnd\033[0m" << std::endl;
	
	return 0;
}