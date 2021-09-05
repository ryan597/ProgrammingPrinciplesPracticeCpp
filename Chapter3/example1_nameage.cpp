#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name and age (followed by 'enter'):\n";
    std::string first_name;
    double age;
    std::cin >> first_name;
    std::cin >> age;
    std::cout << "Hello, " << first_name << "! (age in months " << age * 12 << ")\n";
    return 0;
}