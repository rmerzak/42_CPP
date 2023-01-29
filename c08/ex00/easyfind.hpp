/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:52 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 17:06:53 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>

template <typename T, typename H>
typename T::const_iterator easyfind(T const &container, H k) {
    for (typename T::const_iterator i = container.begin(); i != container.end(); i++) { //// here
        if (k == *i) {
            return i;
        }
    }
    throw std::out_of_range("The element not found");
}

#endif