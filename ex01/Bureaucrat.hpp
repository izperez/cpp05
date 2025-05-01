/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:22:58 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 11:02:30 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade()const;
		class GradeTooHighException;
		class GradeTooLowException;
		void signForm(Form& form) const;
		
		
	private:
		std::string _name;
		int		_grade;
	};
	
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
	
#endif