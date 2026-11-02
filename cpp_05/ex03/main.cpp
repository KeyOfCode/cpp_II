/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:55 by darismen          #+#    #+#             */
/*   Updated: 2025/03/08 19:28:07 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b1("Bob", 1);
	std::cout << b1 << std::endl;
	Intern intern;
	A_Form *ppf;
	A_Form *rrf;
	A_Form *scf;
	
	std::cout << std::endl << "\033[1;32m Test PresidentialPardon \033[0m" << std::endl;
	
	ppf = intern.makeForm("presidential pardon", "Evil");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		b1.signForm(*ppf);
		b1.executeForm(*ppf);
	}

	std::cout << std::endl << "\033[1;32m Test RobotomyRequest \033[0m" << std::endl;

	rrf = intern.makeForm("robotomy request", "Robocop");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
	}

	std::cout << std::endl << "\033[1;32m Test RobotomyRequest \033[0m" << std::endl;

	scf = intern.makeForm("shrubbery creation", "Home");
	if (scf)
	{
		std::cout << *scf << std::endl;
		b1.signForm(*scf);
		b1.executeForm(*scf);
	}


	std::cout << "\033[1;32mEnd\033[0m" << std::endl;
	
	return 0;
}