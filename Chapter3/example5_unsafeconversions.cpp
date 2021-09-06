#include <iostream>

int main()
{
    int a = 20000;
    char c = a;
    // We should instead use {} initializers to avoid unwanted narrowing conversions
    char c {a}; // gives a warning from the compiler
    int b = c;
    if (a != b)
        std::cout << "oops!: " << a << " != " << b << '\n';
    else
        std::cout << "Wow! We have large characters\n";
}