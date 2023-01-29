/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:36:38 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 17:32:46 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size)
{
    v.reserve(size);
}


Span::Span(const Span &D):v(D.v) {
}

Span &Span::operator=(const Span &D) {
    if (this != &D) {
        v = D.v;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int i) {
    if(v.size() < v.capacity())
    {
        v.push_back(i);
    } else
        throw Span::OutOfSize();
}

int Span::longestSpan() {
    if (v.size() < 2)
        throw Span::OutOfElements();
    int max_elem = *std::max_element(this->v.begin(), this->v.end());
    int min_elem = *std::min_element(this->v.begin(), this->v.end());
    return max_elem - min_elem;
}

int Span::shortestSpan() {
    if (v.size() < 2)
        throw Span::OutOfElements();
    std::vector<int> k = this->v;
    sort(k.begin(), k.end());
    int min_span = k[1] - k[0];
    for (size_t i = 1; i < k.size() - 1; ++i) {
        int current_span = k[i+1] - k[i];
        if (current_span < min_span) {
            min_span = current_span;
        }
    }
    return min_span;
}


int & Span::operator[](unsigned int i) {return this->v[i];};
const int & Span::operator[](unsigned int i) const {return this->v[i];};

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    while (first != last) {
        addNumber(*first);
        ++first;
    }
}

unsigned int Span::size(void) {
    return this->v.size();
}