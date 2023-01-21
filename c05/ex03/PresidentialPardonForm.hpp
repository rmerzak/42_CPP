/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:48 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 22:23:44 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm :public AForm
{
private:
    /* data */
public:
    PresidentialPardonForm(/* args */);
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &D);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &D);
    void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
};

#endif
