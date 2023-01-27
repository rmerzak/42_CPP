/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:52 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/27 19:35:45 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>

template <typename T, typename H>
typename T::iterator easyfind(T container, H k) {
    for (typename T::iterator i = container.begin(); i != container.end(); i++) {
        if (k == *i) {
            //std::cout << "found it "<< *i << std::endl;
            return i;
        }
    }
    throw std::out_of_range("The element not found");
}

#endif