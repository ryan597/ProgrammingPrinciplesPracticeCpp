#include <iostream>

// assign p1 to p2
auto main() -> int
{
    int* p1 = new int {20};
    int* p2 = new int[]{1, 2, 4, 8, 16, 32, 64};
    int* p3{p2};

    p1 = p2;
}