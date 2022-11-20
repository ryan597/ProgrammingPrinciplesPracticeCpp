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
    // 1, 2, 3, 4, 5, 6, 7, 8, 9
    int* p1 = new int {20};
    int* p2 = new int[]{1, 2, 4, 8, 16, 32, 64};

    std::cout << "Address " << p1 << " holds the value " << *p1 << '\n';

    for (int i=0; i<7; i++)
    {
        std::cout << "Address " << (p2+i) << " has value " << *(p2+i) << '\n';
    }

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

    // 10, 11, 12
    int* q1 = new int[]{1,2,4,8,16,32,64,128,256,512};
    int* q2 = new int[10];

    for (int i=0; i<10; i++)
    {
        *(q2+i) = *(q1+i);
    }

    // check
    delete[] q1;
    print_array(os, q2, 10);

    delete[] q2;

    // 13
    auto r1 = new std::vector<int>{1,2,4,8,16,32,64,128,256,512};
    auto r2 = new std::vector<int>(10);

    for (int i=0; i<10; i++)
    {
        (*r2)[i] = (*r1)[i];
    }

    // check
    delete r1;
    print_vector(os, r2);

    delete r2;
}