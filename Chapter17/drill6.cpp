#include <iostream>

// allocate array of 11 ints with values 100, 101, 102.. and print the values
auto print_array(std::ostream& os, int num_ints, int* a) -> void
{
    for (int i=0; i<num_ints; i++)
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
    print_array(os, num_ints, a);

    delete[] a;

}