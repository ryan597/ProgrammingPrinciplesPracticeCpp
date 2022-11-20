#include <iostream>
#include <vector>

// Repeat drill 5,6,8 using vector
auto print_vector(std::ostream& os, std::vector<int>* a) -> void
{
    for (auto i:*a)
    {
        os << i << ' ';
    }
    os << '\n';
}


// to test func
auto main() -> int
{
    auto* a = new std::vector<int>{100,101,102,103,104,105,106,107,108,109};
    auto* b = new std::vector<int>{100,101,102,103,104,105,106,107,108,109,110};
    auto* c = new std::vector<int>{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};

    std::ostream& os = std::cout;
    print_vector(os, a);
    print_vector(os, b);
    print_vector(os, c);

    delete a;
    delete b;
    delete c;
}