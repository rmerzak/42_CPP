/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:55:54 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:31:19 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    /* data */
public:
    Intern();
    Intern(const Intern &D);
    Intern &operator=(const Intern &D);
    AForm *makeForm(std::string target, std::string name);
    AForm *none(std::string name);
    AForm *robotomy(std::string name);
    AForm *shrubbery(std::string name);
    AForm *presidential(std::string name);
    ~Intern();
};
