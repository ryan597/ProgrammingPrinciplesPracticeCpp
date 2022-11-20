#include <iostream>

// allocate 20 ints, print the values
auto print_array(std::ostream& os, int* a, int n) -> void
{
    for (int i=0; i<n; i++)
    {
        os << *(a + i) << ' ';
    }
    os << '\n';
}


// to test func
auto main() -> int
{
    int num_ints{20};
    int* a = new int[]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
    std::ostream& os = std::cout;
    print_array(os, a, num_ints);

    delete[] a;

}