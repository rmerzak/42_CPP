/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:54 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:15:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, "RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm():AForm("target", "RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &D):AForm(D.getTarget(), D.getName(), D.getVgrade(), D.getEgrade()) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &D) {
    if(this == &D)
        return *this;
    this->AForm::operator=(D);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (this->getVerified() == false) {throw AForm::FormNotSigned();}
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }
    if(this->getVerified() == true && executor.getGrade() <= this->getEgrade()) {
        srand(time(NULL)); // seed the random number generator
        int success_rate = 50; // success rate is 50%
        int result = rand() % 100 + 1; // generate a random number between 1 and 100
        if (result <= success_rate) {
            std::cout << "The " << this->getTarget() << " has been robotomized successfully." << std::endl;
        } else {
            std::cout << "The operation to robotomize the " << this->getTarget() << " has failed." << std::endl;
        }
    }
}