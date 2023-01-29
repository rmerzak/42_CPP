/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:12:39 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 15:04:56 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    public:
        typedef typename Container::iterator iterator;

        MutantStack() {};
        MutantStack(const MutantStack &D) : std::stack<T, Container>(D){};
        MutantStack &operator=(const MutantStack &D) {
            std::stack<T, Container>::operator=(D);
            return *this;
        }
        ~MutantStack() {};
        iterator   begin()
        {
        return (std::stack<T, Container>::c.begin());
        };

        iterator   end()
        {
            return (std::stack<T, Container>::c.end());
        };

};



#endif