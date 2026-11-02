/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AA_Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darismen <darismen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:00:51 by darismen          #+#    #+#             */
/*   Updated: 2025/01/22 13:20:18 by darismen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class A_Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_grade;
	const int			_exe_grade;
	A_Form();
public:
	A_Form(const A_Form &);
	A_Form(std::string , const int , const int);
	A_Form &operator = (const A_Form &);
	virtual ~A_Form();

	std::string	getName() const;
	int			getSignGrade() const;
	int			getExeGrade() const;
	bool		getIsSigned() const;
	
	bool			beSigned(Bureaucrat &);
	void			execute(Bureaucrat const & executor) const;
	virtual void	startExe(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class SignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator << (std::ostream &o, A_Form const &a);

#endif