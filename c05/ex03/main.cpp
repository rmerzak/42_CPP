/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:54:53 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:47:38 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
   try {
    Bureaucrat a("john", 1);
    // ShrubberyCreationForm f("target");
    // // f.beSigned(a);
    // // f.execute(a);
    // RobotomyRequestForm r("target");
    // PresidentialPardonForm p("target");
    //RobotomyRequestForm v(r);
    // r.beSigned(a);
    // r.execute(a);
    // p.beSigned(a);
    // a.executeForm(p);
    // p.execute(a);

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    rrf->beSigned(a);
    rrf->execute(a);
    }
    catch(std::exception &e) {
        std::cout<< e.what() << std::endl;
    }

    return 1;
}