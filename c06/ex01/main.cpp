/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:54:35 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/22 15:53:30 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

struct Data {
    int x;
    int y;
    char c;
};


uintptr_t serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main()  {
    Data a;

    a.x = 0;
    a.y = 14;
    a.c = 'A';
    uintptr_t z = serialize(&a);
    std::cout<< z << std::endl;
    Data *k = deserialize(z);
    std::cout<< k->c << " " << k->x << " " << k->y << std::endl;

}