/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:19:56 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 19:13:20 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>
class RobotomyRequestForm : public AForm
{
private:
    /* data */
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &D);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &D);
    void execute(Bureaucrat const & executor) const;
    ~RobotomyRequestForm();
};

