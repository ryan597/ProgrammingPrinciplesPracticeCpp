#include <iostream>

// print out the value of p1 and the int it points to
auto main() -> int
{
    int a{7};
    int* p1 = &a;
    std::cout << "Address " << p1 << " holds the value " << *p1 << '\n';
}