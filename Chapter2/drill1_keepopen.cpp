#include <iostream>

inline void keep_window_open() {char ch; std::cin >> ch;}

int main()
{
    std::cout << "Hello World!\n";
    keep_window_open();
    return 0;
}