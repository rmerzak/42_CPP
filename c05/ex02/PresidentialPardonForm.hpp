/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:48 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 19:15:30 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
