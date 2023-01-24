#include <iostream>
#include "iter.hpp"


void printInt(char *i) {
    std::cout << *i;
}

void print(int *i) {
    std::cout << *i;
}

void add(char *i) {
    *i = *i + 1;
}
void addi(int *i) {
    *i = *i + 1;
}

int main(int, char**)
{
   int i[6] = {1,2,3,4,5};
   char str[15] = "hello";
   iter(str,6,add);
   iter(i,6,addi);
   iter(str,6,printInt);
   iter(i,5,print);
    return 0;
}