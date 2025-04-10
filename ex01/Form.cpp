/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:41:00 by izperez           #+#    #+#             */
/*   Updated: 2025/04/10 11:31:33 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int canBeSigned, int canExecute)
	: _name(name), _isSigned(false), _canbeSigned(canBeSigned), _canExecute(canExecute) {
		std::cout << "Form constructor called!" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), 
		_canbeSigned(other._canbeSigned), _canExecute(other._canExecute) {
	std::cout << "Form copy constructor called!" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) { // Protección contra autoasignación
		return (*this);
	}
	std::cout << "Form copy assignment operator called!" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called!" << std::endl;
}


std::string Form::getName() const
{
	return (_name);
}

bool	Form::isSigned() const
{
	return (_isSigned);
}

int Form::canBeSigned() const
{
	return (_canbeSigned);
}

int Form::canExecute() const
{
	return (_canExecute);
}

class Form::GradeTooHighException : public std::exception
{
	public:
	const char* what() const throw() {
	return "Grade is to high!";
	}
};

class Form::GradeTooLowException : public std::exception
{
	public:
	const char* what() const throw() {
	return "Grade is too low!";
	}
};

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _canbeSigned) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName()
		<< ", required grade to sign: " << form.canBeSigned()
		<< ", required grade to execute: " << form.canExecute()
		<< ", is signed: " << (form.isSigned() ? "Yes" : "No");
	return os;
}