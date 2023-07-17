/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:52 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 17:29:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T, typename H>
typename T::const_iterator easyfind(T const &container, H k) {
    typename T::const_iterator i = std::find(container.begin(), container.end(), k);
    if (i == container.end())
        throw std::out_of_range("The element not found");
    return i;
}

#endif
