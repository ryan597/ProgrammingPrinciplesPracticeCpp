#include <iostream>

// print the value of p2 and the array it points to
auto main() -> int
{
    int* p2 = new int[]{1, 2, 4, 8, 16, 32, 64};
    for (int i=0; i<7; i++)
    {
        std::cout << "Address " << (p2+i) << " has value " << *(p2+i) << '\n';
    }
}