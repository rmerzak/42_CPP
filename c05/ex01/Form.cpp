/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:38:12 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 14:46:10 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
Form::Form():name("no_name"),verified(false) ,Vgrade(150), Egrade(150)
{
}

Form::Form(const std::string name,const int V, const int E):name(name),verified(false) ,Vgrade(V), Egrade(E)
{
    if(this->Vgrade < 1 || this->Egrade < 1) {
        throw Form::GradeTooLowException();
    }
    if(this->Vgrade > 150 || this->Egrade > 150) {
        throw Form::GradeTooHighException();
    }
}

Form::~Form()
{
    std::cout << "deconstrector called" << std::endl;
}

Form::Form(const Form &D): name(D.name), Vgrade(D.Vgrade), Egrade(D.Egrade){
    *this = D;
}

Form &Form::operator=( Form const &D ) {
    if (this == &D)
        return *this;
    this->verified = D.verified;
    return *this;
}

const std::string Form::getName(void) const {
    return this->name;
}

bool Form::getVerified(void) const{
    return this->verified;
}
 int Form::getVgrade(void) const{
    return this->Vgrade;
}

 int Form::getEgrade(void) const {
    return this->Egrade;
}

std::ostream &operator<<(std::ostream &output,const Form &D) {
    output << D.getName() + " , Form verified " << D.getVerified() << " , Form valide Grade " << D.getVgrade() << " , Form Execute Grade " << D.getEgrade();
    return output;
}

void Form::beSigned(Bureaucrat &D) {
    if (this->getVerified() == false) {
        if (D.getGrade() <= this->Egrade)
            this->verified = true;
        else
            throw Form::GradeTooLowException();
    }
}
