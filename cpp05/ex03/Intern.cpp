/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:55:57 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:31:09 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &D)
{
    *this = D;
}

Intern &Intern::operator=(const Intern &D) {
    (void)D;
    return *this;
}

AForm *Intern::robotomy(std::string name) {
    std::cout << "intern creates the robotomy request form " <<std::endl;
    return new RobotomyRequestForm(name);
}

AForm *Intern::shrubbery(std::string name) {
    std::cout << "intern creates the shrubbery creation request form " <<std::endl;
    return new ShrubberyCreationForm(name);
}

AForm *Intern::presidential(std::string name) {
    std::cout << "intern creates the presidential pardon request form " <<std::endl;
    return new PresidentialPardonForm(name);
}

AForm *Intern::none(std::string name) {
    (void)name;
    std::cout << " whaaaaaaaat! " <<std::endl;
    return NULL;
}


AForm *Intern::makeForm(std::string target, std::string name) {
    int i;
    AForm * (Intern::*function[4])(std::string name) = {&Intern::none, &Intern::robotomy, &Intern::shrubbery, &Intern::presidential};
    i = (target == "robotomy request") * 1 + (target == "shrubbery creation") * 2 + (target == "presidential pardon") * 3;
    return (this->*function[i])(name);
}