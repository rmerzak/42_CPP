/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:36:43 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 16:53:29 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
class Span
{
private:
    std::vector<int> v;
public:
    Span(unsigned int size);
    Span(const Span &D);
    Span &operator=(const Span &D);
    int &operator[](unsigned int i);
    const int &operator[](unsigned int i)const;
    ~Span();
    void addNumber(int i);
    int shortestSpan();
    int longestSpan();
    unsigned int size();
    class OutOfSize : public std::exception {
     virtual const char* what() const throw() {
        return "Error: cannot add another number!";
    }
  };
      class OutOfElements : public std::exception {
     virtual const char* what() const throw() {
        return "Error: Not enough elements to calculate span.";
    }
  };
  void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
};

