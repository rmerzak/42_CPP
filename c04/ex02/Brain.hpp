/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:30:32 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:46:40 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
class Brain
{
private:
    std::string ideas[100];

public:
    Brain(std::string ideas[100]);
    Brain();
    Brain(const Brain &D);
    Brain &operator=(const Brain &D);
    std::string *getBrain(void);
    void setBrain(std::string ideas[100]);
    ~Brain();
};

#endif