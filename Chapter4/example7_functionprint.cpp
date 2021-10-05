#include <iostream>

void print_square(int v)
{
    std::cout << v << '\t' << v * v << '\n';
}

int main()
{
    for (int i = 0; i < 100; i++)
        print_square(i);
}