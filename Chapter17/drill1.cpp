#include <iostream>
#include <vector>

auto print_vector(std::ostream& os, std::vector<int>* a) -> void
{
    for (auto i:*a)
    {
        os << i << ' ';
    }
    os << '\n';
}

auto print_array10(std::ostream& os, int* a) -> void
{
    for (int i=0; i<10; i++)
    {
        os << *(a + i) << ' ';
    }
    os << '\n';
}

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

    // 1, 2, 3
    int* z = new int[10]{0,1,2,3,4,5,6,7,8,9};
    for (int i=0; i<10; i++)
    {
        std::cout << *(z+i) << '\n';
    }

    delete[] z;

    // 4, 5
    int* y = new int[]{100,101,102,103,104,105,106,107,108,109};
    std::ostream& os = std::cout;
    print_array10(os, y);

    delete[] y;

    // 6, 7, 8, 9
    int num_ints{20};
    int* x = new int[]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
    print_array(os, x, num_ints);

    delete[] x;

    // 10
    auto* a = new std::vector<int>{100,101,102,103,104,105,106,107,108,109};
    auto* b = new std::vector<int>{100,101,102,103,104,105,106,107,108,109,110};
    auto* c = new std::vector<int>{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};

    print_vector(os, a);
    print_vector(os, b);
    print_vector(os, c);

    delete a;
    delete b;
    delete c;
}