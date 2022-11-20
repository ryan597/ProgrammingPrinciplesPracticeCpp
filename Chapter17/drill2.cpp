#include <iostream>

// print the value of the 10 ints
auto main() -> int
{
    int* p = new int[10]{0,1,2,3,4,5,6,7,8,9};
    for (int i=0; i<10; i++)
    {
        std::cout << *(p+i) << '\n';
    }
}