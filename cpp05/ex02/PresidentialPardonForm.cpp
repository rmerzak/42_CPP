/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:45 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:13:37 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm(target, "PresidentialPardonForm", 25, 5)
{
}
PresidentialPardonForm::PresidentialPardonForm(/* args */):AForm("target", "PresidentialPardonForm", 25, 5)
{
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &D):AForm(D.getTarget(), D.getName(), D.getVgrade(), D.getEgrade()) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &D) {
    if(this == &D)
        return *this;
    this->AForm::operator=(D);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (this->getVerified() == false) {throw AForm::FormNotSigned();}
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }
    if(this->getVerified() == true && executor.getGrade() <= this->getEgrade()) {
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}