/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:47:19 by darismen          #+#    #+#             */
/*   Updated: 2025/03/08 19:18:52 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator = (const Intern &rhs)
{
	(void)rhs;
	std::cout << "Intern Assignment Operator Overload Called" << std::endl;
	return *this;
}

A_Form *Intern::makePPF(std::string target)
{
	return new PresidentialPardonForm(target);
}

A_Form *Intern::makeRRF(std::string target)
{
	return new RobotomyRequestForm(target);
}

A_Form *Intern::makeSCF(std::string target)
{
	return new ShrubberyCreationForm(target);
}

A_Form *Intern::makeForm(std::string name, std::string target) const
{
	A_Form *(*all_forms[])(const std::string target) = {&makePPF, &makeRRF, &makeSCF};
	std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	// A_Form *forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return all_forms[i](target);
		}
	}
	std::cout << "Intern cannot create form " << name << ". Form type note recognised" << std::endl;
	return (NULL);
}

std::ostream &operator << (std::ostream &o, Intern const &a)
{
	(void)a;
	o << "Intern << overload called" << std::endl;
	return o;
}

