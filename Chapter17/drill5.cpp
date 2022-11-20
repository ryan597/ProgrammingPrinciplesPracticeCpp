#include <iostream>

// allocate array of 10 ints with values 100, 101, 102.. and print the values
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
    int* a = new int[]{100,101,102,103,104,105,106,107,108,109};
    std::ostream& os = std::cout;
    print_array10(os, a);

    delete[] a;

}