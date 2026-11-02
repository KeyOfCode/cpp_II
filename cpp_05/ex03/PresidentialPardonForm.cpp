/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:18:12 by darismen          #+#    #+#             */
/*   Updated: 2025/04/09 16:20:10 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	A_Form::A_Form("PresidentialPardon", 25, 5), _target("defaultPardon")
{
	std::cout << "\032[0;36m\tPresidentialPardonForm Default Constructor\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	A_Form::A_Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[0;36mPresidentialPardonForm Constructor for target " << this->getTarget() << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	A_Form::A_Form(src), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\x1B[0;31mPresidentialForm" 
		<< " Destructor Called\x1B[0;37m" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::startExe(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "\033[0;34m" << this->_target << 
		" has been pardoned by Zafod Beeblebrox\033[0m" << std::endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &obj)
{
	os << "\033[0;34mForm " << obj.getName() << 
	":\n\t Sign Grade: " << obj.getSignGrade() <<
	"\n\t Execution Grade: " << obj.getSignGrade() <<
	"\n\t is signed: " << obj.getIsSigned() <<
	"\033[0m" << std::endl;
	return os;
}