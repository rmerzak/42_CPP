/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:10 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/24 16:37:21 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}
int main()
{
    std::string a = "hello a";
    std::string b = "world b";
    // std::cout << max(5, 6) << std::endl;
    // std::cout << min(5, 6) << std::endl;
    swap(a, b);
    // swap(z, y);
    std::cout << "a = " << a << " | b = " << b << std::endl;
}