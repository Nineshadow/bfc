#include <iostream>
int mem[4000];
int *i = mem + 2000;
int main(){
    std::cin >> *i;
}
