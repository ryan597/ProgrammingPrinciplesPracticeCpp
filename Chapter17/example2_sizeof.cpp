#include <iostream>

auto main() -> int
{
    char ch{};
    int i{};
    int* pi{};
    bool b{};
    double d{};
    std::cout << "The size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n'
              << "The size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n'
              << "The size of int* is " << sizeof(int*) << ' ' << sizeof(pi) << '\n'
              << "The size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n'
              << "The size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
}