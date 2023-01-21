/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:59:17 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 14:41:01 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat();
    Bureaucrat(const Bureaucrat &D);
    Bureaucrat &operator=(const Bureaucrat &D);
    ~Bureaucrat();
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
};
std::ostream &operator<<(std::ostream &output,const Bureaucrat &D);

#endif