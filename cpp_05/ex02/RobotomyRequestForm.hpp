/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:13:48 by darismen          #+#    #+#             */
/*   Updated: 2025/03/06 12:30:02 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include "Bureaucrat.hpp"

// class A_Form;

class Bureacrat;

class RobotomyRequestForm : public A_Form
{
private:
	const std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &);
	~RobotomyRequestForm();
	
	std::string getTarget(void)const;
	void		startExe(Bureaucrat const & executor) const;
};

std::ostream &operator << (std::ostream &o, RobotomyRequestForm const &a);

#endif