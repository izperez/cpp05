/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:22:58 by izperez           #+#    #+#             */
/*   Updated: 2025/04/08 10:43:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
	public:
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
		
		
		private:
		const std::string _name;
		int		_grade;
	};
	
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
	
#endif