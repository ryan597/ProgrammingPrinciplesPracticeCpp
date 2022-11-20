#include <iostream>

namespace X
{
    int var{};
    auto print() -> void
    {
        std::cout << var << '\n';
    }
}  // X

namespace Y
{
    int var{};
    auto print() -> void
    {
        std::cout << var << '\n';
    }
}  // Y

namespace Z
{
    int var{};
    auto print() -> void
    {
        std::cout << var << '\n';
    }
}  // Z



auto main() -> int
{
    X::var = 7;
    X::print();  // print X's var

    using namespace Y;
    var = 9;
    print();  // print Y's var

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();  // print Z's var
    }

    print();  // print Y's var
    X::print();  // print X's var
}