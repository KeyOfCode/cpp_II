/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:18:12 by darismen          #+#    #+#             */
/*   Updated: 2025/04/09 16:20:10 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	A_Form::A_Form("RobotomyRequest", 72, 45), _target("defaultPardon")
{
	std::cout << "\032[0;35m\tRobotomyRequestForm Default Constructor\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	A_Form::A_Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[0;35mRobotomyRequestForm Constructor for target " << this->getTarget() << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	A_Form::A_Form(src), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm Assignment Operator Overload Called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\x1B[0;31mRobotomyRequestForm" 
		<< " Destructor Called\x1B[0;37m" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::startExe(Bureaucrat const & executor) const
{
	(void)executor;
	srand(time(0));
	std::cout << "\033[1;35m VRRRR!, VRRRR!\033[0m" << std::endl;
	int randomNum = std::rand() % 100;
	if (randomNum < 50)
		std::cout << "\033[1;32mRobotomization was successfull!\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mRobotomization failed\033[0m" << std::endl;
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &obj)
{
	os << "\033[0;34mForm " << obj.getName() << 
	":\n\t Sign Grade: " << obj.getSignGrade() <<
	"\n\t Execution Grade: " << obj.getSignGrade() <<
	"\n\t is signed: " << obj.getIsSigned() <<
	"\033[0m" << std::endl;
	return os;
}