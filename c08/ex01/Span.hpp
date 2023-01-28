/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:36:43 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/28 16:55:02 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
class Span
{
private:
    unsigned int size;
    std::vector<int> v;
public:
    Span(unsigned int size);
    Span(const Span &D);
    Span &operator=(const Span &D);
    int &operator[](unsigned int i) {return this->v[i];};
    const int &operator[](unsigned int i) const {return this->v[i];};
    ~Span();
    void addNumber(int i);
    int shortestSpan();
    int longestSpan();
    unsigned int getSize(void);
    // void FillVector(unsigned int k);
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
  template <typename InputIterator>
  void addNumbers(InputIterator first, InputIterator last) {
    while (first != last) {
        addNumber(*first);
        ++first;
    }
}
};

