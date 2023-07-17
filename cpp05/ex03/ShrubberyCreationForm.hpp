/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:20:01 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/19 14:11:03 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
private:
public:
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &D);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &D);
    void execute(Bureaucrat const & executor) const;
    ~ShrubberyCreationForm();
};
#endif

