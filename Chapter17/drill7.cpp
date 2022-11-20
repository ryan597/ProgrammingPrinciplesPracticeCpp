#include <iostream>

// write func print_array(ostream& os, int* a, int n)
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
    int num_ints{11};
    int* a = new int[]{100,101,102,103,104,105,106,107,108,109,110};
    std::ostream& os = std::cout;
    print_array(os, a, num_ints);

    delete[] a;

}