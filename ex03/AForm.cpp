/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:41:00 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:22:56 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToSigned(0), _gradeToExecute(0)
{
	_isSigned = false;
	std::cout << "Default constructor called!" << std::endl;
}
AForm::AForm(const std::string& name, int canBeSigned, int canExecute)
	: _name(name), _isSigned(false), _gradeToSigned(canBeSigned), _gradeToExecute(canExecute) {
		std::cout << "AForm constructor called for: " << _name << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm destructor called for: " << _name << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), 
		_gradeToSigned(other._gradeToSigned), _gradeToExecute(other._gradeToExecute) {
	std::cout << "AForm copy constructor called!" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		return (*this);
	}
	std::cout << "AForm copy assignment operator called!" << std::endl;
	return *this;
}
std::string AForm::getName() const
{
	return (_name);
}

bool	AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSigned() const
{
	return (_gradeToSigned);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSigned) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm " << AForm.getName()
		<< ", required grade to sign: " << AForm.getGradeToSigned()
		<< ", required grade to execute: " << AForm.getGradeToExecute()
		<< ", is signed: " << (AForm.isSigned() ? "Yes" : "No");
	return os;
}