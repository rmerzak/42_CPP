/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:42 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:05:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat();
    Bureaucrat(const Bureaucrat &D);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &D);
    class GradeTooHighException:public std::exception {
    virtual const char* what() const throw() {
        return "Grade is too High!";
    };
    };
    class GradeTooLowException:public std::exception {
        virtual const char* what() const throw() {
        return "Grade is too Low!";
    }
    };
    void ft_increment(void);
    void ft_decrement(void);
    std::string getName(void) const;
    int getGrade(void) const;
    void signForm(AForm &D);
    void executeForm(AForm const & form);
};
std::ostream &operator<<(std::ostream &output,const Bureaucrat &D);

#endif