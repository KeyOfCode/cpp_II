/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:13:19 by darismen          #+#    #+#             */
/*   Updated: 2025/10/14 13:38:17 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

/* #define NBLK "\x1B[0;30m"
#define NRED "\x1B[0;31m"
#define NWHT "\x1B[0;37m"
#define NBLU "\x1B[0;34m"
 */

class A_Form;

class Bureaucrat
{
	private:
		std::string	_name;
		int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		// Bureaucrat(int grade);
		// Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator = (const Bureaucrat &rhs);
		~Bureaucrat();

		std::string	getName() const;
		int		getGrade() const;

		void	gradeUp(void);
		void	gradeDown(void);
		void	signForm(A_Form &form);
		void	executeForm(A_Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				// GradeTooHighException(); 
				// ~GradeTooHighException() throw() ;
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				// GradeTooLowException(); 
				// ~GradeTooLowException() throw() ;
				virtual const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &o, Bureaucrat const &a);

#endif