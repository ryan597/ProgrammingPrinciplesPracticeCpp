#include <iostream>

// write a function print_array10(ostream& os, int* a) that prints the values of a (assumed to have 10 elememts)
auto print_array10(std::ostream& os, int* a) -> void
{
    for (int i=0; i<10; i++)
    {
        os << *(a + i) << ' ';
    }
    os << '\n';
}


// to test func
auto main() -> int
{
    int* a = new int[]{0,1,2,3,4,5,6,7,8,9};
    std::ostream& os = std::cout;
    print_array10(os, a);

    delete[] a;

}