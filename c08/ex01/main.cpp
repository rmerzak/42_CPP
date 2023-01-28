/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:36:45 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/28 16:56:03 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
int main()
{
    {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    // {
    //     Span s(5);
    //     std::vector<int> numbers = {1, 2, 3, 4, 5};
    //     s.addNumbers(numbers.begin(), numbers.end());
    //     std::cout << "Numbers in the Span: ";
    //     for(size_t i = 0; i < s.getSize(); i++ ) {
    //         std::cout << i << std::endl;
    //     }
    // }

return 0;
}