/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:38:16 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/18 18:01:20 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
    const std::string   name;
    bool                verified;
    const int           Vgrade;
    const int           Egrade;
public:
    Form();
    Form(const std::string name,const int Vgrade, const int Egrade);
    Form(const Form &D);
    Form &operator=(const Form &D);
    ~Form();
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
    const std::string getName(void) const;
    bool getVerified(void) const;
    int getVgrade(void) const;
    int getEgrade(void) const;
    void beSigned(Bureaucrat &D);
};
std::ostream &operator<<(std::ostream &output,const Form &D);

#endif