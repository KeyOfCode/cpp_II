/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:13:19 by darismen          #+#    #+#             */
/*   Updated: 2025/03/08 19:16:24 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* #define NBLK "\x1B[0;30m"
#define NRED "\x1B[0;31m"
#define NWHT "\x1B[0;37m"
#define NBLU "\x1B[0;34m"
 */

class A_Form;

class Intern
{
	private:
	
	public:
		Intern();
		Intern(const Intern &src);
		// Intern(int grade);
		// Intern(std::string name);
		// Intern(std::string name, int grade);
		Intern &operator = (const Intern &rhs);
		~Intern();

		A_Form *makeForm(std::string name, std::string target) const;
		static A_Form *makeSCF(std::string target);
		static A_Form *makeRRF(std::string target);
		static A_Form *makePPF(std::string target);
};

std::ostream &operator << (std::ostream &o, Intern const &a);

#endif