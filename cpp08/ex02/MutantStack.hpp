/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:12:39 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 18:04:48 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

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
        const_iterator   begin() const
        {
        return (std::stack<T, Container>::c.begin());
        };

        const_iterator   end() const
        {
            return (std::stack<T, Container>::c.end());
        };

        reverse_iterator   rbegin()
        {
        return (std::stack<T, Container>::c.rbegin());
        };

        reverse_iterator   rend()
        {
            return (std::stack<T, Container>::c.rend());
        };

        const_reverse_iterator   rbegin() const
        {
        return (std::stack<T, Container>::c.rbegin());
        };

        const_reverse_iterator   rend() const
        {
            return (std::stack<T, Container>::c.rend());
        };

};



#endif