#include <iostream>

int main()
{
    int a = 0;      // int a{0};
    int b = 0;      // int b{0};
    std::cout << "Please enter two integers\n";
    std::cin >> a >> b;

    // My way
    if (a==b)
    {
        std::cout << "a and b are equal\n";
        return 0;
    }
    std::cout << "max(" << a << "," << b << ") is " << ((a<b)? b : a) << "\n";

    // In book
    if (a<b)
        std::cout << "max(" << a << "," << b << ") is " << b <<  "\n";
    else
        std::cout << "max(" << a << "," << b << ") is " << a <<  "\n";
}