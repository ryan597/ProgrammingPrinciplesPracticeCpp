#include <iostream>

// declare an int* p3 and init it with p2
auto main() -> int
{
    int* p2 = new int[]{1, 2, 4, 8, 16, 32, 64};

    int* p3{p2};
    delete[] p3;
}