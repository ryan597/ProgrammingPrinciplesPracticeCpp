#include <iostream>
#include <vector>

// repeat 10, 11, 12 with vectors
auto print_vector(std::ostream& os, std::vector<int>* a) -> void
{
    for (auto i:*a)
    {
        os << i << ' ';
    }
    os << '\n';
}


auto main() -> int
{
    auto p1 = new std::vector<int>{1,2,4,8,16,32,64,128,256,512};
    auto p2 = new std::vector<int>(10);

    for (int i=0; i<10; i++)
    {
        (*p2)[i] = (*p1)[i];
    }

    // check
    delete p1;
    std::ostream& os = std::cout;
    print_vector(os, p2);

    delete p2;
}