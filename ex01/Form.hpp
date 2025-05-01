/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:40:55 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 10:47:47 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string& name, int canBeSigned, int canExecute);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		class GradeTooHighException;
		class GradeTooLowException;
		std::string getName() const;
		bool isSigned() const;
		int getGradeToSigned() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		
	protected:
			const std::string _name;
			bool			_isSigned;
			const int		_gradeToSigned;
			const int		_gradeToExecute;
	};
	
	std::ostream& operator<<(std::ostream& os, const Form& form);

#endif