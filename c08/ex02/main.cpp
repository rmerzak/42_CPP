/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:51:29 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 17:05:13 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    MutantStack<int, std::list<int> > s;
   s.push(5);
   s.push(17);
   s.push(3);
   s.push(5);
   s.push(737);
   s.push(0);
    MutantStack<int, std::list<int> >::iterator t = s.begin();
    MutantStack<int, std::list<int> >::iterator te = s.end();
    while (t != te)
    {
    std::cout << *t << std::endl;
    ++t;
    }
    return 0;
}