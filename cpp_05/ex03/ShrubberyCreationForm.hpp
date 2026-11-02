/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:14:26 by darismen          #+#    #+#             */
/*   Updated: 2025/03/06 12:24:53 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class A_Form;

class Bureacrat;

class ShrubberyCreationForm : public A_Form
{
private:
	const std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
	
	std::string getTarget(void)const;
	void		startExe(Bureaucrat const & executor) const;
};

std::ostream &operator << (std::ostream &o, ShrubberyCreationForm const &a);

#endif