/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:16 by darismen          #+#    #+#             */
/*   Updated: 2025/01/29 13:47:57 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// class A_Form;

class Bureacrat;

class PresidentialPardonForm : public A_Form
{
private:
	const std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &);
	~PresidentialPardonForm();
	
	std::string getTarget(void)const;
	void		startExe(Bureaucrat const & executor) const;
};	

std::ostream &operator << (std::ostream &o, PresidentialPardonForm const &a);

#endif