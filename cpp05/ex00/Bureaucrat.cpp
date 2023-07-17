/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:59:20 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 14:38:13 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int grade) : name(_name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->grade = grade;
    }
}

Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat() : name("no_name"),grade(150)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &D) {
    if(this == &D)
        return *this;
    this->grade = D.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &D) : name(D.name)
{
    this->grade = D.grade;
}

std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::ft_increment(void)
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}


void Bureaucrat::ft_decrement(void)
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}
std::ostream &operator<<(std::ostream &output,const Bureaucrat &D) {
    output << D.getName() + ", bureaucrat grade " << D.getGrade();
    return output;
}
