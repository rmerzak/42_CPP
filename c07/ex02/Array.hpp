/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:52:43 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/26 17:22:19 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array {
  private:
  T *data;
  unsigned int d_size;
  public:
  Array():data(NULL) ,d_size(0) {};
  Array(unsigned int n):data(new T[n]), d_size(n) {};
  ~Array() {
    delete [] this->data;
  };
   Array(const Array<T> &d) : data(new T[d.d_size]), d_size(d.d_size) {
        for (unsigned int i = 0; i < d_size; ++i) {
            this->data[i] = d.data[i];
        }
    };
    Array<T>& operator=(const Array<T> &d) {
        if (this != &d) {
            this->d_size = d.d_size;
            this->data = new T[d_size];
            for (unsigned int i = 0; i < d_size; ++i) {
                this->data[i] = d.data[i];
            }
        }
        return *this;
    };
  class OutOfRange : public std::exception {
     virtual const char* what() const throw() {
        return "Array index out of bounds!";
    }
  };

  T& operator[](unsigned int index) {
        if (index >= d_size) {
            throw Array::OutOfRange();
        }
        return data[index];
    }
  unsigned int size(void) {
    return this->d_size;
  };
};
#endif