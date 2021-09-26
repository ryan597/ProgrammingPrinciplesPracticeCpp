#include <iostream>
#include <cmath>

int main(){
    int i = 0;
    while(i<100){
        std::cout << i << '\t' << pow(i, 2) << '\n';
        ++i;
    }
}