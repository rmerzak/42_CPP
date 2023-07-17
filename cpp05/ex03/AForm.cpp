/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:33 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 22:19:00 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include <iostream>
AForm::AForm():name("no_name"),verified(false) ,Vgrade(1), Egrade(1)
{
}

AForm::AForm(const std::string name,const int V, const int E):name(name),verified(false) ,Vgrade(V), Egrade(E)
{
    if(this->Vgrade < 1 || this->Egrade < 1) {
        throw AForm::GradeTooLowException();
    }
    if(this->Vgrade > 150 || this->Egrade > 150) {
        throw AForm::GradeTooHighException();
    }
}
AForm::AForm(const std::string t,const std::string name,const int V, const int E):name(name),target(t),verified(false) ,Vgrade(V), Egrade(E)
{
    if(this->Vgrade < 1 || this->Egrade < 1) {
        throw AForm::GradeTooLowException();
    }
    if(this->Vgrade > 150 || this->Egrade > 150) {
        throw AForm::GradeTooHighException();
    }
}

AForm::~AForm()
{
    std::cout << "deconstrector called" << std::endl;
}

AForm::AForm(const AForm &D): name(D.name),verified(false) ,Vgrade(D.Vgrade), Egrade(D.Egrade){
}

AForm &AForm::operator=( AForm const &D ) {
    if (this == &D)
        return *this;
    this->verified = D.verified;
    return *this;
}

const std::string AForm::getName(void) const {
    return this->name;
}
const std::string AForm::getTarget(void) const {
    return this->target;
}

bool AForm::getVerified(void) const{
    return this->verified;
}
 int AForm::getVgrade(void) const{
    return this->Vgrade;
}

 int AForm::getEgrade(void) const {
    return this->Egrade;
}

std::ostream &operator<<(std::ostream &output,const AForm &D) {
    output << D.getName() + " , Form verified " << D.getVerified() << " , Form valide Grade " << D.getVgrade() << " , Form Execute Grade " << D.getEgrade();
    return output;
}

void AForm::beSigned(Bureaucrat &D) {
    if (this->getVerified() == false) {
        if (D.getGrade() <= this->Egrade)
            this->verified = true;
        else
            throw AForm::GradeTooLowException();
    }
}
