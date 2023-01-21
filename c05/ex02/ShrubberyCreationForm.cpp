/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:59 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:16:48 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target, "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("target", "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &D): AForm(D.getTarget(), D.getName(), D.getVgrade(), D.getEgrade())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &D) {
    if(this == &D)
        return *this;
    this->AForm::operator=(D);
    return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (this->getVerified() == false) {throw AForm::FormNotSigned();}
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }
    if(this->getVerified() == true && executor.getGrade() <= this->getEgrade()) {
        std::ofstream file(this->getTarget() + "_shrubbery");
        if (file.is_open()) {
            file << " oxoo   oo" <<std::endl;
            file << " ooxoo    oxoo"<<std::endl;
            file << "oxoxoo    ooxoo"<<std::endl;
            file <<"  ooxoxo oo  oxoxooo"<<std::endl;
            file <<" oooo xxoxoo ooo ooox"<<std::endl;
            file <<" oxo o oxoxo  xoxxoxo"<<std::endl;
            file <<"  oxo xooxoooo o ooo"<<std::endl;
            file <<"    oooxoox  /o/o"<<std::endl;
            file <<"        |  |/ /"<<std::endl;
            file <<"        |   /"<<std::endl;
            file <<"        |  |"<<std::endl;
            file <<"        |  |"<<std::endl;
            file <<"        |  |"<<std::endl;
            file <<"        |  |"<<std::endl;
            file <<"  _____/___|____"<<std::endl;
    file.close();
    std::cout << "Tree written to file successfully." << std::endl;
    }
     else {
    std::cout << "Error: Unable to open file for writing." << std::endl;
    }
}
}