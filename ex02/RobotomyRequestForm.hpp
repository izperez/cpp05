/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:02:29 by izperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:08:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define RONOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		void execute(const Bureaucrat &executor) const;
		
	private:
		std::string _target;
	};
	
#endif