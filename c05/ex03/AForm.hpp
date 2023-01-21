/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:37 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 20:05:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
private:
    const std::string   name;
    const std::string   target;
    bool                verified;
    const int           Vgrade;
    const int           Egrade;
public:
    AForm();
    AForm(const std::string name,const int Vgrade, const int Egrade);
    AForm(const std::string target,const std::string name,const int Vgrade, const int Egrade);
    AForm(const AForm &D);
    AForm &operator=(const AForm &D);
    ~AForm();
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
    class FormNotSigned:public std::exception {
        virtual const char* what() const throw() {
        return "the Form is not signed";
    }
    };
    const std::string getName(void) const;
    const std::string getTarget(void) const;
    bool getVerified(void) const;
    int getVgrade(void) const;
    int getEgrade(void) const;
    void beSigned(Bureaucrat &D);
    virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream &operator<<(std::ostream &output,const AForm &D);

#endif