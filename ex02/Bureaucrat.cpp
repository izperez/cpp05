/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:59:16 by izperez           #+#    #+#             */
/*   Updated: 2025/04/18 10:59:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
	const char* what() const throw() {
	return "Grade is to high!";
	}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
	const char* what() const throw() {
	return "Grade is too low!";
	}
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
	_grade = grade;
	std::cout << "Bureaucrat Constructor called for: " << _name << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destructor called for: " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat Copy Constructor called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat Assignment Operator called!" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);  // Llama a beSigned de Form pasando el Bureaucrat
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const GradeTooLowException& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
