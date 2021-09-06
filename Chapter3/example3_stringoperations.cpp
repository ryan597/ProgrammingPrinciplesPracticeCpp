#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first and second names\n";
    std::string first;
    std::string second;
    std::cin >> first >> second;
    std::string name = first + ' ' + second;
    std::cout << "Hello, " << name << '\n';
}