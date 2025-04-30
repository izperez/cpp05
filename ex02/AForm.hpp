/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:40:55 by izperez           #+#    #+#             */
/*   Updated: 2025/04/25 11:16:52 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string& name, int canBeSigned, int canExecute);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw() {
			return "Grade is to high!";
			}
		};

		class GradeTooLowException : public std::exception
		{
			
			public:
			const char* what() const throw() {
				return "Grade is too low!";
			}
		};
		std::string getName() const;
		bool isSigned() const;
		int getGradeToSigned() const;
		virtual int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		
		private:
			const std::string _name;
			bool			_isSigned;
			const int		_gradeToSigned;
			const int		_gradeToExecute;
	};
	
	std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif

/* **** Clase abstracta ****
 * No se puede instanciar
 * Contiene al menos un método virtual puro
 * Se utiliza como base para clases derivadas que implementan los métodos.
 */

/* **** Clase no abstracta ****
 * Se puede instanciar
 * Puede contener métodos implementados y se utiliza tanto como base como clase independiente.
 */