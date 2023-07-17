/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:13:43 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/28 21:01:40 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"




template< typename T >
void print( T const & x ) { std::cout << x << std::endl; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };


  iter( tab, 5, print);


  return 0;
}
