#include <iostream>

// copy values from array pointed to by p1 to array pointed to by p2
auto print_array(std::ostream& os, int* a, int n) -> void
{
    for (int i=0; i<n; i++)
    {
        os << *(a + i) << ' ';
    }
    os << '\n';
}

auto main() -> int
{
    int* p1 = new int[]{1,2,4,8,16,32,64,128,256,512};
    int* p2 = new int[10];

    for (int i=0; i<10; i++)
    {
        *(p2+i) = *(p1+i);
    }

    // check
    delete[] p1;
    std::ostream& os = std::cout;
    print_array(os, p2, 10);

    delete[] p2;
}