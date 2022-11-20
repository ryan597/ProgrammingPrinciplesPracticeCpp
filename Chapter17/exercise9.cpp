#include <iostream>

// deallocate the memory
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
    int* p1 = new int {20};
    int* p2 = new int[]{1, 2, 4, 8, 16, 32, 64};
    int* p3{p2};

    delete p1;
    p1 = p2;
    p3 = p2;

    std::ostream& os = std::cout;
    os << "Address " << p1 << " holds ";
    print_array(os, p1, 7);
    os << "Address " << p1 << " holds ";
    print_array(os, p2, 7);

    delete[] p2;

}